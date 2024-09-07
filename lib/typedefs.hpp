#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

#include <map>
#include <vector>

template <typename T>
using vec = std::vector<T>;
using vec_i = vec<int>;
template <typename T, typename U>
using umap = std::unordered_map<T, U>;
using str = std::string;

using pair_ii = std::pair<int, int>;

using uint = unsigned int;

#endif  // TYPEDEFS_HPP