#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
int l, r;
bool vis[N];
bool fit[N];
bool subfit[N];
int val[N];

// 是否是合数
bool st[N];
int p[N], cnt;

int trans(int x) {
    int ret{};
    while (x) {
        ret += (x % 10) * (x % 10);
        x /= 10;
    }
    return ret;
}

void sel() {
    for (int i{2}; i <= 10000; ++i) {
        if (!st[i]) p[++cnt] = i;
        for (int j{1}; 1ll * i * p[j] <= 10000; ++j) {
            st[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}

vector<int> getpath(int x) {
    vector<int> path;
    unordered_set<int> con;
    int cur{x};
    while (cur != 1 && !con.count(cur)) {
        con.emplace(cur);
        path.emplace_back(cur);
        cur = trans(cur);
    }

    if (cur == 1) {
        // path.emplace_back(1);
        return path;
    }
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l >> r;
    sel();
    for (int i{l}; i <= r; ++i) {
        vector<int> path{getpath(i)};
        if (!path.empty()) {
            fit[i] = true;
            val[i] = path.size();
            for (int j{1}; j < path.size(); ++j) {
                if (path[j] >= l && path[j] <= r) {
                    subfit[path[j]] = true;
                }
            }
        }
    }

    bool has{};
    for (int i{l}; i <= r; ++i) {
        if (fit[i] && !subfit[i]) {
            has = true;
            if (!st[i]) val[i] *= 2;
            cout << i << " " << val[i] << "\n";
        }
    }
    if (!has) cout << "SAD\n";
    return 0;
}
