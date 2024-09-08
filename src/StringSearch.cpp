#include "StringSearch.hpp"

vec_i knuthMorrisPratt(str text, str pat) {
    int n = text.size(), m = pat.size();
    // Longest (proper) Prefix Suffix
    vec_i lps(m, 0);

    int len = 0;
    for (int i = 1; i < m; i++) {
        while (len > 0 && pat[i] != pat[len]) {
            len = lps[len - 1];
        }
        len += (pat[i] == pat[len]);
        lps[i] = len;
    }

    // Search text for pat
    int i = 0, j = 0;
    vec_i matches;

    while (i < n) {
        if (j >= m || pat[j] != text[i]) {
            if (j >= m) {
                matches.push_back(i - m);
            } else if (j == 0) {
                i++;
                continue;
            }
            j = lps[j - 1];
        } else {
            i++;
            j++;
        }
    }

    return matches;
}

vec_i boyerMoore(str text, str pat) { return vec_i(); }
