#include "ShortestPath.hpp"

#include <gtest/gtest.h>

class ShortestPathTest : public ::testing::Test {
   protected:
    vec<vec<pair_ii>> graph = {
        {{1, 10}, {2, 3}}, {{3, 2}}, {{1, 4}, {3, 8}, {4, 2}}, {{4, 5}}, {}};
};

TEST_F(ShortestPathTest, Dijkstra) {
    ASSERT_EQ(dijkstra(0, 3, graph).second, 9);
}
