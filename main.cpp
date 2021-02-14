#include "Goldbergs.h"

int main()
{
    const char* filepath = "/Users/ddulaev/Desktop/DenseSubgraph/edges.txt";
    auto graph = Goldbergs(filepath);
    auto subgraph = graph.binsearch_goldberg();
    for (auto& v : subgraph)
    {
        std::cout << v;
    }
    return 0;
}