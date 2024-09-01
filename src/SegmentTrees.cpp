#include "SegmentTrees.hpp"

SegmentNode::SegmentNode() {}

SegmentNode::SegmentNode(int low, int high, const vec_i *values)
    : m_low(low), m_high(high) {
    m_lazy = 0;
    m_values = values;
    m_left = NULL;
    m_right = NULL;

    if (low == high) {
        m_value = values->at(low);
    } else {
        int middle = (low + high) / 2;
        m_left = new SegmentNode(low, middle, values);
        m_right = new SegmentNode(middle + 1, high, values);
        m_value =
            m_left->getValue() + m_right->getValue();  // operation applied here
    }
}

void SegmentNode::setLazy(int lazy) { m_lazy = lazy; }

void SegmentNode::applyLazy() {
    if (m_lazy != 0) {
        m_value += m_lazy * (m_high - m_low + 1);  // operation applied here
        if (m_left) m_left->setLazy(m_lazy);
        if (m_right) m_right->setLazy(m_lazy);
        m_lazy = 0;
    }
}

int SegmentNode::queryRange(int low, int high) {
    applyLazy();

    if (low <= m_low && high >= m_high) {
        return m_value;
    } else if (low > m_high || high < m_low) {
        return 0;
    } else {
        return m_left->queryRange(low, high) +
               m_right->queryRange(low, high);  // operation applied here
    }
}

int SegmentNode::updateRange(int low, int high, int diff) {
    applyLazy();

    if (low <= m_low && high >= m_high) {
        m_lazy += diff;
        return diff * (m_high - m_low + 1);
    } else if (low > m_high || high < m_low) {
        return 0;
    } else {
        // operation applied here
        int totalDiff = m_left->updateRange(low, high, diff + m_lazy) +
                        m_right->updateRange(low, high, diff + m_lazy);
        m_value += totalDiff;
        return totalDiff;
    }
}

int SegmentNode::getValue() { return m_value; }

// Segment tree

SegmentTree::SegmentTree() {}

SegmentTree::SegmentTree(vec_i values) {
    if (values.empty()) {
        throw std::invalid_argument("empty values vector received");
    }

    m_low = 0;
    m_high = values.size() - 1;
    m_values = vec_i(values);
    m_root = std::make_unique<SegmentNode>(0, m_high, &m_values);
}

int SegmentTree::queryRange(int low, int high) {
    if (low > high || low < m_low || high > m_high) {
        throw std::invalid_argument("invalid arguments received");
    }

    return m_root->queryRange(low, high);
}

void SegmentTree::updateRange(int low, int high, int diff) {
    if (low > high || low < m_low || high > m_high) {
        throw std::invalid_argument("invalid arguments received");
    }
    if (diff == 0) return;

    m_root->updateRange(low, high, diff);
}
