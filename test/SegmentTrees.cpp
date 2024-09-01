#include "SegmentTrees.hpp"

#include <gtest/gtest.h>

class SegmentTreeTest : public ::testing::Test {
   protected:
    vec_i values;
    vec_i lazy;
    SegmentTree* tree;

    void SetUp() override {
        values = {1, 2, 3, 4, 5};
        lazy = {0, 0, 0, 0, 0};
        auto tree = new SegmentTree(values);
    }

    void TearDown() override { delete tree; }
};

TEST_F(SegmentTreeTest, Initialization) {
    EXPECT_NO_THROW(SegmentTree newTree(values));
}

TEST_F(SegmentTreeTest, QueryRangeValid) {
    EXPECT_EQ(tree->queryRange(0, 2), 6);
    EXPECT_EQ(tree->queryRange(1, 3), 9);
}

TEST_F(SegmentTreeTest, QueryRangeInvalid) {
    EXPECT_THROW(tree->queryRange(-1, 2), std::invalid_argument);
    EXPECT_THROW(tree->queryRange(2, 1), std::invalid_argument);
    EXPECT_THROW(tree->queryRange(0, 10), std::invalid_argument);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}