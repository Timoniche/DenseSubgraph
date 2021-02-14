//
// Created by Dmitrii Dulaev on 14.02.2021.
//

#ifndef DENSESUBGRAPH_GOLDBERGS_H
#define DENSESUBGRAPH_GOLDBERGS_H

#include "MaxFlowBoostWrapper.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

struct Goldbergs
{
public:
#define DENSE_TYPE 4

    explicit Goldbergs(const char *filename)
    {
        graph_from_file(filename);
    }

    /**
     * @return subgraph related to the maximum dense
     */
    std::vector<int> binsearch_goldberg();

    float count_density(std::vector<int> const& subgraph);

    void graph_from_file(const char *filename);

    std::vector<int> find_subgraph_dense_more_than(float least_density);

private:
    std::size_t _nodes_cnt{};
    std::size_t _edges_cnt{};
    std::vector<int> _degrees;
    std::vector<std::pair<int, int>> _edges;

    static const int MAX_NODES_CNT = 100000;
};

std::vector<int> Goldbergs::binsearch_goldberg()
{
    float l_dens = 0.f;
    auto r_dens = static_cast<float>(_edges_cnt);
    std::vector<int> subgraph{};
    float delta = 1.f / float(_nodes_cnt * (_nodes_cnt + 1));
    while (r_dens - l_dens >= delta)
    {
        std::cout << "..." << std::endl;
        float cur_least_dens = l_dens + (r_dens - l_dens) / 2.f;
        std::vector<int> cur_subgraph = find_subgraph_dense_more_than(cur_least_dens);
        if (cur_subgraph.empty())
        {
            r_dens = cur_least_dens;
        } else
        {
            l_dens = cur_least_dens;
            subgraph = cur_subgraph;
        }
    }
    return subgraph;
}

/**
 *
 * @param subgraph Pre: not empty
 */
float Goldbergs::count_density(std::vector<int> const& subgraph)
{
    assert(!subgraph.empty() && "subgraph can't be empty");
    float dens = 0.f;
    float vertices_cnt = subgraph.size();
    std::unordered_set<int> vertices(subgraph.begin(), subgraph.end());
    for (auto& e : _edges)
    {
        if (vertices.contains(e.first) && vertices.contains(e.second))
        {
            dens += 2.f;
        }
    }
    return dens / (2.f * vertices_cnt);
}

void Goldbergs::graph_from_file(const char *filename)
{
    freopen(filename, "r", stdin);
    int v1;
    int v2;
    int max_vertex_num = -1;
    _degrees = std::vector<int>(MAX_NODES_CNT, 0);
    while (std::cin >> v1 >> v2)
    {
        _edges.emplace_back(v1, v2);
        _degrees[v1]++;
        _degrees[v2]++;
        max_vertex_num = std::max(max_vertex_num, std::max(v1, v2));
    }
    _edges_cnt = _edges.size();
    _nodes_cnt = max_vertex_num + 1;

}

std::vector<int> Goldbergs::find_subgraph_dense_more_than(float least_density)
{
    auto graph = MaxFlowBoostWrapper(_nodes_cnt);
    for (auto &e : _edges)
    {
        graph.addBidirectionalEdge(e.first, e.second, 1, 1);
    }
    for (int i = 0; i < _nodes_cnt; i++)
    {
        graph.addTerminalEdges(i, _edges_cnt,
                               static_cast<float>(_edges_cnt) + 2.0f * least_density - static_cast<float>(_degrees[i]));
    }
    std::cout << "Max Flow for density " << least_density << " is: " << graph.calculateMaxFlow() << std::endl;
    std::vector<int> subgraph{};
    for (int i = 0; i < _nodes_cnt; i++)
    {
        if (graph.groupOf(i) == DENSE_TYPE)
        {
            subgraph.push_back(i);
        }
    }
    std::cout << "[";
    for (auto& v : subgraph)
    {
        std::cout << v;
    }
    std::cout << "]" << std::endl;
    return subgraph;
}


#endif //DENSESUBGRAPH_GOLDBERGS_H
