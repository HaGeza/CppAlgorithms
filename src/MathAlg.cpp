#include "MathAlg.hpp"

#include <algorithm>

int GCD(int a, int b) {
    if (a < b) std::swap(a, b);

    int remainder;
    while (b != 0) {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int LCM(int a, int b) { return a * b / GCD(a, b); }

vec_i primeFactors(int num) {
    vec_i factors;

    int i = 2;
    while (i <= num / i && i <= 3) {
        if (num % i == 0) {
            factors.push_back(i);
            num /= i;
        } else {
            i += 1;
        }
    }
    int step = 2;
    i = 5;
    while (i <= num / i) {
        if (num % i == 0) {
            factors.push_back(i);
            num /= i;
        } else {
            i += step;
            step = 6 - step;
        }
    }
    if (num > 1) factors.push_back(num);
    return factors;
}

void addToSieve(vec<bool> &sieve, int factor) {
    for (int i = factor; i <= sieve.size(); i += factor) {
        sieve[i - 1] = true;
    }
}

vec_i primeSieve(int max) {
    vec_i primes;
    vec<bool> sieve(max, false);

    for (int factor : {2, 3}) {
        if (max >= factor) {
            addToSieve(sieve, factor);
            primes.push_back(factor);
        } else {
            return primes;
        }
    }

    int factor = 5, step = 2;
    while (factor <= max / factor) {
        if (!sieve[factor - 1]) {
            addToSieve(sieve, factor);
            primes.push_back(factor);
        }
        factor += step;
        step = 6 - step;
    }

    for (; factor <= sieve.size(); factor += step, step = 6 - step) {
        if (!sieve[factor - 1]) {
            primes.push_back(factor);
        }
    }

    return primes;
};

uint fastProduct(uint a, uint b) {
    int prod = 0;
    while (b > 0) {
        prod += (b & 1) * a;
        a <<= 1;
        b >>= 1;
    }
    return prod;
};

float fastPower(float base, uint exponent) {
    float pow = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            pow *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    return pow;
};

float nthRoot(float x, int n) {
    float prev, diff, eps = 0.00000001, base = x, xn;

    x = x / 3;
    do {
        prev = x;
        xn = fastPower(x, n);
        x = x - (xn - base) / (n * xn / x);
        diff = x - prev;
    } while (diff > eps || -diff > eps);

    return x;
};
