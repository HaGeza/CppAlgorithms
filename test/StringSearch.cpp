#include "StringSearch.hpp"

#include <gtest/gtest.h>

class StringSearchTest : public ::testing::Test {
   protected:
    vec<str> texts = {"ABAAAABAACD", "AAAAABAAAAABA"};
    vec<str> pats = {"ABA", "AAAA"};
    vec<vec_i> results = {{0, 5}, {0, 1, 6, 7}};
};

TEST_F(StringSearchTest, knuthMorrisPrattWorks) {
    for (int k = 0; k < texts.size(); k++) {
        str text = texts[k], pat = pats[k];
        vec_i expectedMatches = results[k];

        vec_i matches = knuthMorrisPratt(text, pat);
        ASSERT_EQ(matches.size(), expectedMatches.size());
        for (int i = 0; i < matches.size(); i++) {
            ASSERT_EQ(matches[i], expectedMatches[i]);
        }
    }
}

TEST_F(StringSearchTest, boyerMooreWorks) {
    for (int k = 0; k < texts.size(); k++) {
        str text = texts[k], pat = pats[k];
        vec_i expectedMatches = results[k];

        vec_i matches = boyerMoore(text, pat);
        ASSERT_EQ(matches.size(), expectedMatches.size());
        for (int i = 0; i < matches.size(); i++) {
            ASSERT_EQ(matches[i], expectedMatches[i]);
        }
    }
}
