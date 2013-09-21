#include "fitzhugh_nagumo.h"

FitzHugh_Nagumo::FitzHugh_Nagumo() :
    DynamicalSystem(2,0,1)
{
    this->a = 0;
    this->epsilon = 0.01;
    this->dt = 0.01;
}

FitzHugh_Nagumo::FitzHugh_Nagumo(double a) :
    DynamicalSystem(2,0,1)
{
    this->a = a;
    this->epsilon = 0.01;
    this->dt = 0.01;
}

void FitzHugh_Nagumo::init()
{
    Vars[0] = 0;
    Vars[1] = 0.1;
    dVars[0] = dVars[1] = 0;
}

void FitzHugh_Nagumo::compute(double t)
{
    dVars[0] = Vars[0]-Vars[0]*Vars[0]*Vars[0]/3.0-Vars[1];
    dVars[1] = epsilon*(Vars[0]-Vars[1]+a);
}
