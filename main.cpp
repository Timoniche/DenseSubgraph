#include "Goldbergs.h"

int main()
{
    const char* filepath = "/Users/ddulaev/Desktop/DenseSubgraph/edges.txt";
    auto graph = Goldbergs(filepath);
    auto subgraph = graph.binsearch_goldberg();
    std::cout << "subgraph answer: " << std::endl;
    for (auto& v : subgraph)
    {
        std::cout << v;
    }
    std::cout << std::endl;
    float max_density = graph.count_density(subgraph);
    std::cout << "max density: " << max_density << std::endl;
    return 0;
}