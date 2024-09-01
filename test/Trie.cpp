#include "Trie.hpp"

#include <gtest/gtest.h>

#include <thread>

class TrieTest : public ::testing::Test {
   protected:
    vec<str> keys;
    Trie trie;

    void SetUp() override {
        keys = {"abc", "ab", "aaa", "be", "bebe", "abba", "ha%"};
        trie = Trie(keys);
    }
};

TEST_F(TrieTest, Initialization) { EXPECT_NO_THROW(Trie newTrie(keys)); }

TEST_F(TrieTest, FindWorks) {
    for (auto key : keys) {
        EXPECT_TRUE(trie.find(key));
    }

    EXPECT_FALSE(trie.find("lol"));
    EXPECT_FALSE(trie.find("aaaa"));
    EXPECT_FALSE(trie.find("abbba"));
}

TEST_F(TrieTest, RemoveWorks) {
    EXPECT_TRUE(trie.remove("bebe"));
    EXPECT_FALSE(trie.find("bebe"));
    EXPECT_TRUE(trie.find("be"));

    EXPECT_TRUE(trie.remove("abc"));
    EXPECT_FALSE(trie.find("abc"));
    EXPECT_TRUE(trie.find("ab"));

    EXPECT_TRUE(trie.remove("ha%"));
    EXPECT_FALSE(trie.find("ha%"));

    EXPECT_FALSE(trie.remove("lulz"));
    EXPECT_FALSE(trie.remove("x"));
    EXPECT_FALSE(trie.remove("HEHEHE"));
}

TEST_F(TrieTest, InsertWorks) {
    EXPECT_FALSE(trie.find("lulz"));
    EXPECT_TRUE(trie.insert("lulz"));
    EXPECT_TRUE(trie.find("lulz"));

    EXPECT_FALSE(trie.find("x"));
    EXPECT_TRUE(trie.insert("x"));
    EXPECT_TRUE(trie.find("x"));

    EXPECT_FALSE(trie.find("HEHEHE"));
    EXPECT_TRUE(trie.insert("HEHEHE"));
    EXPECT_TRUE(trie.find("HEHEHE"));

    EXPECT_FALSE(trie.insert("abba"));
    EXPECT_FALSE(trie.insert("ha%"));
}
