#include <bits/stdc++.h>
using namespace std;

const int N = 33;
int n;
int in[N], pre[N];

struct Node {
    int _val;
    Node* _left, *_right;
    Node(int val = 0) : _val(val), _left(nullptr), _right(nullptr) {}
};

unordered_map<int, int> mp;

struct Tree {
    Node* root;

    void levelorder() {
        queue<Node*> q;
        q.emplace(root);
        bool is_first{true};
        while (q.size()) {
            int sz(q.size());
            while (sz--) {
                auto u{q.front()}; q.pop();
                if (!is_first) cout << " ";
                else is_first = false;
                cout << u->_val;
                if (u->_left) {
                    q.emplace(u->_left);
                }
                if (u->_right) {
                    q.emplace(u->_right);
                }
            }
        }
        cout << "\n";
    }

    // pre [根左右]
    // in  [左根右]
    // post[左右根]
    Node* build(int in_left, int in_right, int pre_left, int pre_right) {
        if (in_left > in_right || pre_left > pre_right) return nullptr;
        Node* cur = new Node(pre[pre_left]);
        int idx{mp[pre[pre_left]]};
        int left_sz{idx - in_left};
        cur->_right = build(in_left, idx - 1, pre_left + 1, pre_left + left_sz);
        cur->_left = build(idx + 1, in_right, pre_left + left_sz + 1, pre_right);
        return cur;
    }
}tr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{1}; i <= n; ++i) {
        cin >> in[i];
        mp[in[i]] = i;
    }
    for (int i{1}; i <= n; ++i) cin >> pre[i];
    tr.root = tr.build(1, n, 1, n);
    tr.levelorder();
    return 0;
}
