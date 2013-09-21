#ifndef DYNAMICAL_SYSTEM_H
#define DYNAMICAL_SYSTEM_H
#include <vector>
class DynamicalSystem{
public:
    int systemSize; /**< the dimension of the dynamical system */
    std::vector<double> Vars; /**< pointer to the array of dynamical variables */
    std::vector<double> dVars; /**< pointer to the array of derivatives of the dynamical variables */
    double derivativeSplitThreshold;
    double splitStepFactor;
    double dt; /**integration step for this model*/
    DynamicalSystem(int systemSize, double derivativeSplitThreshold,
                    double splitStepFactor){
        this->systemSize = systemSize;
        this->derivativeSplitThreshold = derivativeSplitThreshold;
        this->splitStepFactor = splitStepFactor;
        Vars.resize(systemSize);
        dVars.resize(systemSize);
    }

    virtual void init() = 0;

    /** calculate derivatives of the dynamical variables at the time moment t
        @param t - time moment
     */
    virtual void compute(double t) = 0;
    double getVar(int i){
        return Vars[i];
    }
    double getDerivative(int i){
        return dVars[i];
    }
};

#endif // DYNAMICAL_SYSTEM_H
