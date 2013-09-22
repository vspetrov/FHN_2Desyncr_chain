#include "NetworkSolver.h"

int NetworkSolver::idCounter = 0;

NetworkSolver::NetworkSolver()
{
}


template<class T> NetworkSolver::addChain(int chainSize, int boundaryConditions)
{
    for (int i=0; i<chainSize; i++)    {
        network.push_back(NetworkElement<T>());
    }
}

template <class T>NetworkElement<T>::NetworkElement()
{
    id = NetworkSolver::idCounter++;
    system = T();
    system->init();
}
