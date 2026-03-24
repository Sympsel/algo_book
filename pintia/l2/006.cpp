#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int _val;
    TreeNode* _left, *_right;
    TreeNode(int val) : _val(val), _left(nullptr), _right(nullptr) {}
};

TreeNode* root;
unordered_map<int, int> mp;
const int N = 33;
int n;
int in[N], post[N];

TreeNode* build(int il, int ir, int pl, int pr) {
    if (il > ir || pl > pr) return nullptr;
    TreeNode* cur = new TreeNode(post[pr]);
    int idx{mp[post[pr]]};
    int left_sz{idx - il};
    cur->_left = build(il, il + idx - 1, pl, pl + left_sz - 1);
    cur->_right = build(idx + 1, ir, pl + left_sz, pr - 1);
    return cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> post[i];
    for (int i{1}; i <= n; ++i) {
        cin >> in[i];
        mp[in[i]] = i;
    }
    TreeNode* root = build(1, n, 1, n);
    queue<TreeNode*> q;
    q.emplace(root);
    bool is_first{true};
    while (q.size()) {
        int sz(q.size());
        while (sz--) {
            auto cur{q.front()}; q.pop();
            if (!is_first) cout << " ";
            else is_first = false;
            cout << cur->_val;

            if (cur->_left) {
                q.emplace(cur->_left);
            }
            if (cur->_right) {
                q.emplace(cur->_right);
            }
        }
    }
    return 0;
}