#ifndef DESOLVER_H
#define DESOLVER_H
#include <DynamicalSystem.h>
#include <math.h>
#include <fstream>
/** @brief This is a general differential equations solver class
  */
class DESolver{
    std::ofstream output;
    double dumpInterval;
    bool doWriteOutput;
    bool showProgress;
public:

    DESolver(){
        doWriteOutput = false;
        dumpInterval = -1;
    }

    ~DESolver();
    /** integrate a cell over single "small" time step
        @param system - pointer to the cell to be integrated
        @param dt - time step
        @param time - current time
      */
    virtual void IntegrateOverDt(DynamicalSystem *system, double dt,
                                 double time = 0,
                                 bool inSplitPhase = false) = 0;

    /** solves dynamical equations over given time period
        @param cell - pointer to the cell to be integrated
        @param MaxTime - time period in milliseconds
        @param dt - time step
      */
    void Solve(DynamicalSystem *system, double MaxTime = 1000,
               double dt = 0.005);
    void setOutputFile(std::string filename);
    void setDumpInterval(double interval);
    void enableWriteOutput();
    void enableShowProgress();
};

/** @brief class implementing forward Euler integration method
  */
class ForwardEulerSolver:public DESolver{
    int splitVariableIndex;
    bool enableSplitting;
public:
    ForwardEulerSolver(){
        splitVariableIndex = 0;
        enableSplitting = false;
    }

    /** integrate a cell over single "small" time step
        @param cell - pointer to the cell to be integrated
        @param dt - time step
        @param time - current time
      */
    void IntegrateOverDt(DynamicalSystem *system,
                         double dt, double time = 0,
                         bool inSplitPhase = false);
    void setSplitVariableIndex(int index);
    void enaleStepSplitting();
};

#endif // DESOLVER_H
