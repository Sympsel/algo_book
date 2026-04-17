#include <bits/stdc++.h>
using namespace std;

struct node {
    int data, lazy;
};

void build(vector<int>& data, vector<node>& tree, int root, int left, int right) {
    if (left == right) {
        tree[root].data = data[left];
        return;
    }
    int mid = left + (right - left) / 2;
    int lc = root << 1;
    build(data, tree,  lc, left, mid);
    build(data, tree, lc | 1, mid + 1, right);
    tree[root].data = max(tree[lc].data, tree[lc | 1].data);
}

void push_down(vector<node>& tree, int root) {
    if (tree[root].lazy) {
        int lc = root << 1, rc = lc | 1;
        tree[lc].data += tree[root].lazy;
        tree[rc].data += tree[root].lazy;
        tree[lc].lazy += tree[root].lazy;
        tree[rc].lazy += tree[root].lazy;
        tree[root].lazy = 0;
    }
}

int query(vector<node>& tree, int p, int left, int right, int ql, int qr) {
    if (ql > right || qr < left) return INT_MIN;
    if (ql <= left && qr >= right) return tree[p].data;
    push_down(tree, p);
    int mid = left + ((right - left) >> 1);
    int left_query = query(tree, p << 1, left, mid, ql, qr);
    int right_query = query(tree, p << 1 | 1, mid + 1, right, ql, qr);
    return max(left_query, right_query);
}

void update(vector<node>& tree, int root, int left, int right, int idx, int val) {
    if (left == right) {
        tree[root].data = val;
        return;
    }
    int mid = left + ((right - left) >> 1);
    if (idx <= mid) {
        update(tree, root << 1, left, mid, idx, val);
    } else {
        update(tree, root << 1 | 1, mid + 1, right, idx, val);
    }
    tree[root].data = max(tree[root << 1].data, tree[root << 1 | 1].data);
}

void update_range(vector<node>& tree, int root, int left, int right, int ul, int ur, int val) {
    if (ul > right || ur < left) return;
    if (ul <= left && ur >= right) {
        tree[root].data += val;
        tree[root].lazy += val;
        return;
    }
    push_down(tree, root);
    int mid = left + ((right - left) >> 1);
    update_range(tree, root << 1, left, mid, ul, ur, val);
    update_range(tree, root << 1 | 1, mid + 1, right, ul, ur, val);
    tree[root].data = max(tree[root << 1].data, tree[root << 1 | 1].data);
}

int main() {

    return 0;
}