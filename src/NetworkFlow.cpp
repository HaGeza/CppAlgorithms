#include "NetworkFlow.hpp"

#include <queue>

std::pair<vec_i, int> DFS(int node, int sink, wdag &flowGraph, int currentFlow,
                          vec<bool> &seen) {
    seen[node] = true;
    if (node == sink) return std::pair<vec_i, int>({sink}, currentFlow);

    int flow = 0;
    for (auto edge : flowGraph[node]) {
        int next = edge.first, capacity = edge.second;
        if (seen[next] || capacity <= 0) continue;

        auto pathAndFlow =
            DFS(next, sink, flowGraph, std::min(currentFlow, capacity), seen);
        flow = pathAndFlow.second;
        if (flow > 0) {
            vec_i path = pathAndFlow.first;
            path.emplace_back(node);
            return std::pair<vec_i, int>(path, flow);
        }
    }
    return std::make_pair<vec_i, int>({}, 0);
}

std::pair<vec_i, int> DFS(int source, int sink, wdag &flowGraph) {
    vec<bool> seen = vec<bool>(flowGraph.size(), false);
    auto pathAndFlow = DFS(source, sink, flowGraph, INT_MAX, seen);
    vec_i path = pathAndFlow.first;
    int flow = pathAndFlow.second;

    std::reverse(path.begin(), path.end());

    return std::pair<vec_i, int>(path, flow);
}

const int NO_PARENT = -1, START_PARENT = -2;

std::pair<vec_i, int> BFS(int source, int sink, wdag &flowGraph) {
    vec<int> parent = vec<int>(flowGraph.size(), NO_PARENT);

    std::queue<std::tuple<int, int, int>> queue;
    queue.push({START_PARENT, source, INT_MAX});

    std::tuple<int, int, int> info;
    int node, capacity, flow;
    while (!queue.empty()) {
        info = queue.front();
        queue.pop();

        node = std::get<1>(info);

        if (parent[node] != NO_PARENT) continue;
        parent[node] = std::get<0>(info);
        capacity = std::get<2>(info);

        if (node == sink) {
            flow = capacity;
            break;
        }

        for (auto edge : flowGraph[node]) {
            if (edge.second > 0) {
                queue.push({node, edge.first, std::min(edge.second, capacity)});
            }
        }
    }

    if (node != sink) return {vec_i(), 0};

    vec_i path = vec_i({node});
    while (node != source) {
        node = parent[node];
        path.emplace_back(node);
    }
    std::reverse(path.begin(), path.end());
    return {path, flow};
}

int fordFulkerson(int source, int sink, vec<vec<pair_ii>> &graph, int n,
                  std::pair<vec_i, int> (*findPath)(int, int, wdag &)) {
    auto flowGraph = vec<umap<int, int>>(n);
    for (int i = 0; i < graph.size(); i++) {
        for (auto edge : graph[i]) {
            int j = edge.first;
            flowGraph[i][j] = edge.second;
            flowGraph[j][i] = 0;
        }
    }
    int totalFlow = 0;

    auto pathAndFlow = findPath(source, sink, flowGraph);
    vec_i path = pathAndFlow.first;
    int flow = pathAndFlow.second;
    while (flow > 0) {
        totalFlow += flow;
        for (int i = 0; i < path.size() - 1; i++) {
            int from = path[i], to = path[i + 1];
            flowGraph[from][to] -= flow;
            flowGraph[to][from] += flow;
        }
        pathAndFlow = findPath(source, sink, flowGraph);
        path = pathAndFlow.first;
        flow = pathAndFlow.second;
    }
    return totalFlow;
}

int fordFulkerson(int source, int sink, vec<vec<pair_ii>> &graph, int n) {
    return fordFulkerson(source, sink, graph, n, &DFS);
}

int edmondKarp(int source, int sink, vec<vec<pair_ii>> &graph, int n) {
    return fordFulkerson(source, sink, graph, n, &BFS);
}