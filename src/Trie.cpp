#include "Trie.hpp"

Trie::Trie() : m_isKey(false) {}

Trie::Trie(vec<str> keys) {
    m_edges = umap<char, TrieChild>();
    m_isKey = false;

    auto children_by_start = umap<char, vec<str>>();

    for (auto key : keys) {
        if (key.empty()) {
            m_isKey = true;
            continue;
        }
        char c = key[0];
        children_by_start[c].push_back(key.substr(1));
    }

    for (auto &it : children_by_start) {
        m_edges[it.first] = std::make_unique<Trie>(it.second);
    }
}

bool Trie::find(str s) {
    if (s.empty()) return m_isKey;

    auto child = m_edges.find(s[0]);
    if (child == m_edges.end()) return false;
    return child->second->find(s.substr(1));
}

std::pair<bool, bool> Trie::removeUtil(str s) {
    if (s.empty()) {
        bool removed = m_isKey;
        return {removed, m_edges.empty()};
    }

    auto child = m_edges.find(s[0]);
    if (child == m_edges.end()) return {false, false};

    auto result = child->second->removeUtil(s.substr(1));
    bool removed = result.first, deleteChild = result.second;

    if (deleteChild) m_edges.erase(s[0]);
    return {removed, !m_isKey && m_edges.empty()};
}

bool Trie::remove(str s) { return removeUtil(s).first; }

bool Trie::insert(str s) {
    if (s.empty()) {
        bool inserted = !m_isKey;
        m_isKey = true;
        return inserted;
    }

    auto child = m_edges.find(s[0]);
    if (child == m_edges.end()) {
        m_edges[s[0]] = std::make_unique<Trie>();
        return m_edges[s[0]]->insert(s.substr(1));
    } else {
        return child->second->insert(s.substr(1));
    }
}
