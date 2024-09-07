#include "MathAlg.hpp"

#include <gtest/gtest.h>

class MathAlgTest : public ::testing::Test {};

TEST_F(MathAlgTest, GCDWorks) {
    ASSERT_EQ(GCD(4, 2), 2);
    ASSERT_EQ(GCD(12, 9), 3);
    ASSERT_EQ(GCD(12, 5), 1);
    ASSERT_EQ(GCD(162, 117), 9);
    ASSERT_EQ(GCD(143, 1313), 13);
}

TEST_F(MathAlgTest, LCMWorks) {
    ASSERT_EQ(LCM(4, 2), 4);
    ASSERT_EQ(LCM(12, 9), 36);
    ASSERT_EQ(LCM(12, 5), 60);
    ASSERT_EQ(LCM(162, 117), 2106);
    ASSERT_EQ(LCM(143, 1313), 14443);
}

TEST_F(MathAlgTest, primeFactorizationWorks) {
    vec_i factors = primeFactors(6481356);
    vec_i expectedFactors = {2, 2, 3, 7, 19, 31, 131};

    int n = expectedFactors.size();
    ASSERT_EQ(factors.size(), n);

    for (int i = 0; i < n; i++) {
        ASSERT_EQ(factors[i], expectedFactors[i]);
    }
}

TEST_F(MathAlgTest, primeSieveWorks) {
    vec_i primes = primeSieve(50);
    vec_i expectedPrimes = {2,  3,  5,  7,  11, 13, 17, 19,
                            23, 29, 31, 37, 41, 43, 47};

    int n = expectedPrimes.size();
    ASSERT_EQ(primes.size(), n);

    for (int i = 0; i < n; i++) {
        ASSERT_EQ(primes[i], expectedPrimes[i]);
    }
}

TEST_F(MathAlgTest, fastProductWorks) {
    ASSERT_EQ(fastProduct(10, 3), 30);
    ASSERT_EQ(fastProduct(7, 81), 567);
    ASSERT_EQ(fastProduct(63, 111), 6993);
}

TEST_F(MathAlgTest, fastPowerWorks) {
    ASSERT_FLOAT_EQ(fastPower(3.0, 5), 243.0);
    ASSERT_FLOAT_EQ(fastPower(12.81, 3), 2102.071041);
}

TEST_F(MathAlgTest, nthRootWorks) {
    ASSERT_FLOAT_EQ(nthRoot(2.0, 2), 1.4142135624);
    ASSERT_FLOAT_EQ(nthRoot(78595.0, 5), 9.5296946157);
}
