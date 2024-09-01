#include "SegmentTrees.hpp"

#include <gtest/gtest.h>

#include <thread>

class SegmentTreeTest : public ::testing::Test {
   protected:
    vec_i values;
    vec_i lazy;
    std::unique_ptr<SegmentTree> tree;

    void SetUp() override {
        values = {1, 2, 3, 4, 5};
        lazy = {0, 0, 0, 0, 0};
        tree = std::make_unique<SegmentTree>(values);
    }

    // void TearDown() override { tree.reset(); }
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

TEST_F(SegmentTreeTest, UpdateRangeValid) {
    tree->updateRange(1, 3, 2);  // 1, 4, 5, 6, 5
    EXPECT_EQ(tree->queryRange(0, 4), 21);
    tree->updateRange(0, 2, -1);  // 0, 3, 4, 6, 5
    tree->updateRange(4, 4, 10);  // 0, 3, 4, 6, 15
    EXPECT_EQ(tree->queryRange(0, 4), 28);
}

TEST_F(SegmentTreeTest, UpdateRangeInvalid) {
    EXPECT_THROW(tree->updateRange(-1, 2, 1), std::invalid_argument);
    EXPECT_THROW(tree->updateRange(2, 1, 3), std::invalid_argument);
    EXPECT_THROW(tree->updateRange(0, 10, -1), std::invalid_argument);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}