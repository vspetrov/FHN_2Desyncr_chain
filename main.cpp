#include <iostream>
#include <string>
#include <DESolver.h>
#include <fitzhugh_nagumo.h>
int main()
{
    try{
        FitzHugh_Nagumo fhn(0);
        fhn.init();
        ForwardEulerSolver fes;
        fes.enableWriteOutput();
        fes.setOutputFile("rst.dat");
        fes.setDumpInterval(1);
        fes.enableShowProgress();
        fes.Solve(&fhn,1000,0.001);
    }
    catch(std::string strerr){
        std::cerr << strerr << std::endl;
    }

    return 0;
}
