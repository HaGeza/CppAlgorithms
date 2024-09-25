#ifndef TRIE_HPP
#define TRIE_HPP

#include "typedefs.hpp"

class Trie {
    umap<char, std::unique_ptr<Trie>> m_edges;
    bool m_isKey;

    std::pair<bool, bool> removeUtil(str s);

   public:
    Trie();
    Trie(vec<str> keys);
    bool find(str s);
    bool remove(str s);
    bool insert(str s);
};

typedef std::unique_ptr<Trie> TrieChild;

#endif  // TRIE_HPP
