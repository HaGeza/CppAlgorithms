#ifndef SEGMENTTREES_HPP
#define SEGMENTTREES_HPP

#include <stdexcept>
#include <vector>

typedef std::vector<int> vec_i;

class SegmentNode {
    int m_low, m_high, m_value, m_lazy;
    SegmentNode *m_left, *m_right;
    const vec_i *m_values;

   public:
    SegmentNode();
    SegmentNode(int low, int high, const vec_i *values);
    void setLazy(int lazy);
    void applyLazy();
    int queryRange(int low, int high);
    int updateRange(int low, int high, int diff);
    int getValue();
};

class SegmentTree {
    int m_low, m_high;
    vec_i m_values;
    std::unique_ptr<SegmentNode> m_root;

   public:
    SegmentTree();
    SegmentTree(vec_i values);
    int queryRange(int low, int high);
    void updateRange(int low, int high, int diff);
};

#endif  // SEGMENTTREES_HPP