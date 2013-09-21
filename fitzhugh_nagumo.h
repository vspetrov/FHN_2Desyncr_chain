#ifndef FITZHUGH_NAGUMO_H
#define FITZHUGH_NAGUMO_H
#include <DynamicalSystem.h>

class FitzHugh_Nagumo : public DynamicalSystem
{
private:
    double epsilon;
    double a;
public:
    FitzHugh_Nagumo();
    FitzHugh_Nagumo(double a);
    virtual void init();
    virtual void compute(double t);
};

#endif // FITZHUGH_NAGUMO_H
