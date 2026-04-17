#ifndef _SEGMENT_TREE_
#define _SEGMENT_TREE_

#include <iostream>
#include <vector>

namespace sym {
struct Node {
    int _left, _right;
    int _sum;

    Node(int _sum = 0) : _left(0), _right(0), _sum(_sum) {}
};


template <class T>
class SegmentTree {
   public:
    SegmentTree(int sz) : _sz(sz) {
        tr.resize(_sz << 2);
    }

    // SegmentTree(Node* arr, int sz) : _sz(sz) {
    //     tr.resize(_sz << 2);
    //     build(arr, 1, 0, _sz - 1);
    // }

    SegmentTree(std::vector<Node> arr) : _sz(arr.size()) {
        tr.resize(_sz << 2);
        build(arr, 1, 0, _sz - 1);
    }

    void push_up(int idx) {
        tr[idx]._sum = tr[idx << 1]._sum + tr[idx << 1 | 1]._sum;
    }

    void build(const std::vector<Node>& arr, int l, int r, int idx) {
        if (l == r) {
            tr[idx] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(arr, l, mid, idx << 1);
        build(arr, mid + 1, r, idx << 1 | 1);
        push_up(idx);

    }

   private:
    size_t _sz;
    std::vector<Node> tr;
};
}  // namespace sym

#endif  // _SEGMENT_TREE_
