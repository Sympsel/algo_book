#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n;
int a[N];
int w[N];

struct node {
    int val, id;
    node(int _val = 0, int _id = 0) : val(_val), id(_id) {}

    bool operator<(const node& o) const {
        if (val == o.val) {
            return id < o.id;
        }
        return val > o.val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, q;
    cin >> n >> r >> q;
    int t{n};
    n *= 2;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    for (int i{1}; i <= n; ++i) cin >> w[i];
    priority_queue<node> q1;
    priority_queue<node> q2;
    for (int i{1}; i <= n; ++i) {
        q1.emplace(a[i], i);
    }

    while (r--) {
        for (int i{1}; i <= t; ++i) {
            auto [val1, id1]{q1.top()}; q1.pop();
            auto [val2, id2]{q1.top()}; q1.pop();
            if (w[id1] > w[id2]) {
                q2.emplace(val1 + 1, id1);
                q2.emplace(val2, id2);
            } else {
                q2.emplace(val2 + 1, id2);
                q2.emplace(val1, id1);
            }
        }
        swap(q1, q2);
    }
    while (--q) {
        q1.pop();
    }
    cout << q1.top().id << "\n";
    return 0;
}