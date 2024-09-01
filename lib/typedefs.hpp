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

#endif  // TYPEDEFS_HPP