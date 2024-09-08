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

vec_i boyerMoore(str text, str pat) {
    int n = text.size(), m = pat.size();

    // Bad character shift
    vec_i bcs(m);
    umap<char, int> lastOccurrenceTable;
    for (int i = 0; i < m; i++) {
        auto lastIt = lastOccurrenceTable.find(pat[i]);
        bcs[i] = lastIt == lastOccurrenceTable.end() ? -1 : lastIt->second;
        lastOccurrenceTable[pat[i]] = i;
    }

    // Good suffix position & good suffix shift
    vec_i gsp(m, 0), gss(m, 0);
    gsp[m - 1] = m;
    int j = m;
    for (int i = m - 1; i > 0; i--) {
        while (j < m && pat[i - 1] != pat[j - 1]) {
            if (gss[i] == 0) {
                gss[j] = j - i;
            }
            j = gsp[j];
        }
        j -= (pat[i - 1] == pat[j - 1]);
        gsp[i - 1] = j;
    }

    return vec_i();
}
