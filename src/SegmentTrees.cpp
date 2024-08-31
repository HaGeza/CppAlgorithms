#include <stdio.h>

#include <stdexcept>
#include <vector>

typedef std::vector<int> vec_i;

class SegmentNode {
    int m_low, m_high, m_value, m_lazy;
    SegmentNode *m_left, *m_right;
    const vec_i *m_values;

   public:
    SegmentNode() {};

    SegmentNode(int low, int high, const vec_i *values)
        : m_low(low), m_high(high), m_values(values) {
        m_left = nullptr;
        m_right = nullptr;
        m_lazy = 0;

        if (low == high) {
            m_value = values->at(low);
        } else {
            int middle = (low + high) / 2;
            m_left = new SegmentNode(low, middle, values);
            m_right = new SegmentNode(middle + 1, high, values);
            m_value = m_left->getValue() +
                      m_right->getValue();  // operation applied here
        }
    }

    ~SegmentNode() {
        if (m_left) {
            delete m_left;
            delete m_right;
        }
    }

    void setLazy(int lazy) { m_lazy = lazy; }

    void applyLazy() {
        if (m_lazy != 0) {
            m_value += m_lazy * (m_high - m_low + 1);  // operation applied here
            m_left->setLazy(m_lazy);
            m_right->setLazy(m_lazy);
            m_lazy = 0;
        }
    }

    int queryRange(int low, int high) {
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

    int updateRange(int low, int high, int diff) {
        applyLazy();

        if (low <= m_low && high >= m_high) {
            m_lazy += diff;
            return diff * (m_high - m_low + 1);
        } else if (low > m_high || high < m_low) {
            return 0;
        } else {
            int diffLeft = m_left->updateRange(low, high, diff + m_lazy);
            int diffRight = m_right->updateRange(low, high, diff + m_lazy);
            m_value += diffLeft + diffRight;  // operation applied here
        }
    }

    int getValue() { return m_value; }
};

class SegmentTree {
    int m_low, m_high;
    vec_i m_values;
    SegmentNode m_root;

   public:
    SegmentTree(vec_i values, vec_i lazy) {
        m_low = 0;
        m_high = m_values.size() - 1;
        m_values = vec_i(values);
        m_root = SegmentNode(0, m_high, &values);
    }

    int queryRange(int low, int high) {
        if (low > high || low < m_low || high > m_high) {
            throw std::invalid_argument("invalid arguments received");
        }

        return m_root.queryRange(low, high);
    }
};

int main() {
    printf("Hi lel\n");

    return 0;
}