#include <stdio.h>

#include <vector>

typedef std::vector<int> vec_i;

class SegmentNode {
    int m_low, m_high, m_value;
    SegmentNode *m_left, *m_right;
    vec_i *m_values, *m_lazy;

   public:
    SegmentNode() {};

    SegmentNode(int low, int high, vec_i *values, vec_i *lazy)
        : m_low(low), m_high(high), m_values(values), m_lazy(lazy) {
        m_left = nullptr;
        m_right = nullptr;

        if (low == high) {
            m_value = values->at(low);
        } else {
            int middle = (low + high) / 2;
            m_left = new SegmentNode(low, middle, values, lazy);
            m_right = new SegmentNode(middle + 1, high, values, lazy);
            m_value = m_left->getValue() +
                      m_right->getValue();  // operation applied here
        }
    }

    int rangeQuery(int low, int high) {}

    int getValue() { return m_value; }
};

class SegmentTree {
    int m_high;
    vec_i m_values, m_lazy;
    SegmentNode m_root;

   public:
    SegmentTree(vec_i values, vec_i lazy) {
        m_high = m_values.size() - 1;
        m_values = vec_i(values);
        m_lazy = vec_i(m_values.size(), 0);
        m_root = SegmentNode(0, m_high, &values, &lazy);
    }
};

int main() {
    printf("Hi lel\n");

    return 0;
}