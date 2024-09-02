#include "ShortestPath.hpp"

#include <queue>

const int NO_PARENT = -1, START_PARENT = -2;

using triple = std::tuple<int, int, int>;

std::pair<vec_i, int> dijkstra(int start, int end, vec<vec<pair_ii>> &graph) {
    int n = graph.size();
    auto parent = vec_i(n, NO_PARENT);

    std::priority_queue<triple, std::vector<triple>, std::greater<triple>> pq;
    pq.push({0, start, START_PARENT});

    triple element;
    int node, dist, minDist = INT_MAX;
    while (!pq.empty()) {
        element = pq.top();
        pq.pop();

        node = std::get<1>(element);
        if (parent[node] != NO_PARENT) continue;
        parent[node] = std::get<2>(element);

        dist = std::get<0>(element);
        if (node == end) {
            minDist = dist;
            break;
        }

        for (auto edge : graph[node]) {
            if (parent[edge.first] == NO_PARENT) {
                pq.push({dist + edge.second, edge.first, node});
            }
        }
    }

    if (node != end) return {vec_i(), minDist};

    vec_i path = vec_i({node});
    while (node != start) {
        node = parent[node];
        path.emplace_back(node);
    }
    std::reverse(path.begin(), path.end());
    return {path, minDist};
}
