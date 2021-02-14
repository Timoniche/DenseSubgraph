#include <iostream>
#include "MaxFlowBoostWrapper.h"

int main()
{
    auto g = MaxFlowBoostWrapper(2);
    g.addBidirectionalEdge(1, 2, 1, 1);
    g.addTerminalEdges(1, 1, 0);
    g.addTerminalEdges(2, 0, 1);
    std::cout << "Max flow: " << g.calculateMaxFlow() << std::endl;
    return 0;
}