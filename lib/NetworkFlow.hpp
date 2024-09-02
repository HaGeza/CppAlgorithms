#include <climits>

#include "typedefs.hpp"

using wdag = vec<umap<int, int>>;

std::pair<vec_i, int> DFS(int node, int sink, wdag &flowGraph, int currentFlow,
                          vec<bool> &seen);

std::pair<vec_i, int> DFS(int source, int sink, wdag &flowGraph);

int fordFulkerson(int source, int sink, vec<vec<pair_ii>> graph, int n);
