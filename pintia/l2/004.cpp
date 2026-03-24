#include <bits/stdc++.h>
using namespace std;

vector<int> tar, a, b;

struct TreeNode {
    int _val;
    TreeNode* _left, *_right;
    TreeNode(int val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : _val(val), _left(left), _right(right) {}
};
struct Tree {
    TreeNode* root;

    void add(int val) {
        TreeNode* new_node = new TreeNode(val);
        if (root == nullptr) {
            root = new_node;
        } else {
            add(root, new_node);
        }
    }

    void add(TreeNode* cur, TreeNode* new_node) {
        if (new_node->_val >= cur->_val) {
            if (cur->_right == nullptr) {
                cur->_right = new_node;
            } else {
                add(cur->_right, new_node);
            }
        } else {
            if (cur->_left == nullptr) {
                cur->_left = new_node;
            } else {
                add(cur->_left, new_node);
            }
        }
    }

    void preorder(bool flag = true) {
        preorder(root, flag);
    }

    void preorder(TreeNode* cur, bool flag) {
        if (cur == nullptr) {
            return;
        }
        if (flag) {
            a.emplace_back(cur->_val);
            preorder(cur->_left, flag);
            preorder(cur->_right, flag);
        } else {
            b.emplace_back(cur->_val);
            preorder(cur->_right, flag);
            preorder(cur->_left, flag);
        }
    }

    void postorder(bool flag = true) {
        postorder(root, flag);
    }

    void postorder(TreeNode* cur, bool flag) {
        static bool _first{true};
        if (cur == nullptr) {
            return;
        }
        if (flag) {
            postorder(cur->_left, flag);
            postorder(cur->_right, flag);
        } else {
            postorder(cur->_right, flag);
            postorder(cur->_left, flag);
        }
        if (_first) {
            cout << cur->_val;
            _first = false;
        } else {
            cout << " " << cur->_val;
        }
    }
}tr;

int n;

void build() {
    int _;
    for (int i{1}; i <= n; ++i) {
        cin >> _;
        tr.add(_);
        tar.emplace_back(_);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    build();
    tr.preorder();
    tr.preorder(false);
    bool st{true};
    for (int i{}; i < n; ++i) {
        if (a[i] != tar[i]) {
            st = false;
            break;
        }
    }
    if (st) {
        cout << "YES\n";
        tr.postorder();
        return 0;
    }
    st = true;
    for (int i{}; i < n; ++i) {
        if (b[i] != tar[i]) {
            st = false;
            break;
        }
    }
    if (st) {
        cout << "YES\n";
        tr.postorder(false);
        return 0;
    }
    cout << "NO";
    return 0;
}
