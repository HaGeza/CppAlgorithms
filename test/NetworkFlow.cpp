#include "NetworkFlow.hpp"

#include <gtest/gtest.h>

class NetworkFlowTest : public ::testing::Test {
   protected:
    vec<vec<pair_ii>> graph = {{{1, 16}, {2, 13}},
                               {{2, 10}, {3, 12}},
                               {{1, 4}, {4, 14}},
                               {{2, 9}, {5, 20}},
                               {{3, 7}, {5, 4}}};
};

TEST_F(NetworkFlowTest, FordFulkerson) {
    ASSERT_EQ(fordFulkerson(0, 5, graph, 6), 23);
}
