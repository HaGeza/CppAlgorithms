#include "Manacher.hpp"

void expandPalindrome(std::string &s, int &l, int &r, int n_centers) {
    while (l > 0 && r < n_centers && s[l / 2 - 1] == s[(r - 1) / 2 + 1]) {
        l -= 2;
        r += 2;
    }
    l += (l + 1) % 2;
    r -= (r + 1) % 2;
}

pair_ii LPS(std::string s) {
    int n = s.length(), n_centers = 2 * n + 1;
    auto lpsAt = vec_i(n_centers);

    int l = 0, ml = 0, m = 0, mr = 0, r = 0;
    int lpsMax = 0, lpsMaxPos = 0;

    for (; mr < n_centers; mr++) {
        if (mr >= m + lpsAt[m]) {
            m = l = r = mr;
        }
        ml = 2 * m - mr;
        if (lpsAt[ml] < r - mr) {
            lpsAt[mr] = lpsAt[ml];
        } else {
            m = mr;
            l = 2 * m - r;
            expandPalindrome(s, l, r, n_centers);
            lpsAt[mr] = r - mr + 1;
        }
        if (lpsAt[mr] > lpsMax) {
            lpsMax = lpsAt[mr];
            lpsMaxPos = mr;
        }
    }

    for (auto l : lpsAt) {
        printf("%d ", l);
    };
    printf("\n");

    return {lpsMax, lpsMaxPos};
}
