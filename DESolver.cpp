#include "DESolver.h"
#include <algorithm>
#include <iterator>
#include <iostream>
DESolver::~DESolver()
{
    if (output.is_open())
        output.close();
}

void DESolver::Solve(DynamicalSystem *system, double MaxTime,
                     double dt)
{
    if (doWriteOutput && !output.is_open()){
        throw(std::string("Write output flag was set, but no output file was specified"));
    }

    if (doWriteOutput && dumpInterval < 0){
        throw(std::string("Write output flag was set, but dumpInterval was not set"));
    }
    unsigned long int MT = (unsigned long int)MaxTime/dt;
    int dumpCounter = 0;
    int progressStep = (int)(MT/100.0);
    if (system->Vars.size() == 0){
        throw(std::string("Error:Dynamical system has 0 dimensionality"));
    }
    std::cout << "***** Solve started *****"  << std::endl;
    for (unsigned long int i = 1; i <= MT; i++){
        double time = i*dt;
        this->IntegrateOverDt(system,dt,time);
        if (doWriteOutput && time > dumpInterval*dumpCounter-1E-10){
            output << time << " ";
            for (size_t j=0; j<system->Vars.size(); j++){
                output << system->Vars[j] << " ";
            }
            output << "\n";
            dumpCounter++;
        }

        if (showProgress && i/progressStep*progressStep == i){
            std::cout << "Progress: " << i/progressStep << "%" << std::endl;
        }
    }
    std::cout << "***** Solve finished *****"  << std::endl;
}

void DESolver::setOutputFile(std::string filename)
{
    output.open(filename.c_str());
}

void DESolver::setDumpInterval(double interval)
{
    if (interval < 0)
        throw(std::string("Error: setting dump interval with negative value"));
    dumpInterval = interval;
}

void DESolver::enableWriteOutput()
{
    doWriteOutput = true;
}

void DESolver::enableShowProgress()
{
    showProgress = true;
}

void ForwardEulerSolver::IntegrateOverDt(DynamicalSystem *system,
                                         double dt, double time,
                                         bool inSplitPhase)
{
    system->compute(time);

    double dV = system->getDerivative(splitVariableIndex);
    if (enableSplitting && fabs(dV) > system->derivativeSplitThreshold && !inSplitPhase){
        double split_dt = dt/system->splitStepFactor;
        for (int i=0; i<int(system->splitStepFactor); i++){
            this->IntegrateOverDt(system,split_dt,time+split_dt*i,true);
        }
    }else{
        for (int i=0; i<system->systemSize; i++){
            system->Vars[i] += dt*system->dVars[i];
        }
    }
}
void ForwardEulerSolver::setSplitVariableIndex(int index)
{
    splitVariableIndex = index;
}

void ForwardEulerSolver::enaleStepSplitting()
{
    enableSplitting = true;
}
