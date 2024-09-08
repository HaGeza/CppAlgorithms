#include "Manacher.hpp"

#include <gtest/gtest.h>

class ManacherTest : public ::testing::Test {
   protected:
    str s = std::string("babcbabcbaccba");
};

// The LPS has length 9 and starts at position 11
TEST_F(ManacherTest, LPSWorks) {
    pair_ii expected = {9, 11};
    ASSERT_EQ(LPS(s), expected);
}
