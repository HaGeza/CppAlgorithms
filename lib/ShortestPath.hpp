#ifndef SHORTEST_PATH_HPP
#define SHORTEST_PATH_HPP

#include "typedefs.hpp"

std::pair<vec_i, int> dijkstra(int start, int end, vec<vec<pair_ii>> &graph);

#endif  // SHORTEST_PATH_HPP
