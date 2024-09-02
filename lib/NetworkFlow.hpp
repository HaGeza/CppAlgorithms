#include <climits>

#include "typedefs.hpp"

std::pair<vec_i, int> DFS(int node, int sink, vec<vec<pair_ii>> &flowGraph,
                          int currentFlow, vec<bool> &seen);

std::pair<vec_i, int> DFS(int source, int sink, vec<vec<pair_ii>> &flowGraph);

int fordFulkerson(int source, int sink, vec<vec<pair_ii>> graph);
