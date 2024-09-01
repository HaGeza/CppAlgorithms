#ifndef SEGMENTTREES_HPP
#define SEGMENTTREES_HPP

#include <stdexcept>
#include <vector>

#include "typedefs.hpp"

class SegmentNode {
    int m_low, m_high, m_value, m_lazy;
    std::unique_ptr<SegmentNode> m_left, m_right;
    std::shared_ptr<vec_i> m_values;

   public:
    SegmentNode();
    SegmentNode(int low, int high, std::shared_ptr<vec_i> values);
    void setLazy(int lazy);
    void applyLazy();
    int queryRange(int low, int high);
    int updateRange(int low, int high, int diff);
    int getValue();
};

class SegmentTree {
    int m_low, m_high;
    SegmentNode m_root;

   public:
    SegmentTree();
    SegmentTree(vec_i values);
    int queryRange(int low, int high);
    void updateRange(int low, int high, int diff);
};

#endif  // SEGMENTTREES_HPP