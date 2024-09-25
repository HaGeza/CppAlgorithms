#ifndef MATH_ALG_HPP
#define MATH_ALG_HPP

#include "typedefs.hpp"

int GCD(int a, int b);

int LCM(int a, int b);

vec_i primeFactors(int num);

vec_i primeSieve(int max);

uint fastProduct(uint a, uint b);

float fastPower(float base, uint exponent);

float nthRoot(float base, int n);

#endif  // MATH_ALG_HPP
