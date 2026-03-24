#include <bits/stdc++.h>
using namespace std;

const int N = 53;
unordered_set<int> st[N];
int n;

void solve(const int& x, const int& y) {
    unordered_set<int> sum;
    for (auto u : st[x]) {
        sum.emplace(u);
    }
    for (auto u : st[y]) {
        sum.emplace(u);
    }
    double ret{100.0};
    ret *= (double)(st[x].size() + st[y].size() - sum.size()) / sum.size();
    cout << fixed << setprecision(2) << ret << "%\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int sz, _;

    for (int i{1}; i <= n; ++i) {
        cin >> sz;
        for (int j{}; j < sz; ++j) {
            cin >> _;
            st[i].emplace(_);
        }
    }
    int k; cin >> k;
    int x, y;
    while (k--) {
        cin >> x >> y;
        solve(x, y);
    }

    return 0;
}
