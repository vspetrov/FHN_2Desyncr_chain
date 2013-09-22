#ifndef NETWORKSOLVER_H
#define NETWORKSOLVER_H
#include "DESolver.h"
#include "DynamicalSystem.h"

template <class T>
class NetworkElement
{

public:
    DynamicalSystem *system;
    DESolver solver;
    int id;
    std::vector<int> connectedTo;
    std::vector<double> couplings;
    NetworkElement();
};

class NetworkSolver
{
    std::vector<NetworkElement> network;
public:
    static int idCounter;
    NetworkSolver();
    enum {
        CHAIN_BOUNDARY_FREE,
        CHAIN_BOUNDARY_PERIODIC
    };
    template<class T> addChain(int chainSize, int boundaryConditions);
};

#endif // NETWORKSOLVER_H
