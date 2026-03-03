#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
int n;
unordered_map<int, int> mp;
unordered_set<int> st[N];
int pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int m, _;
    while (n--) {
        cin >> m; ++pos;
        for (int i{}; i < m; ++i) {
            cin >> _;
            st[pos].emplace(_);
            ++mp[_];
        }
    }

    int ret{};
    int ma{};
    for (auto& [k, v] : mp) {
        if (v > ma || v == ma && ret < k) {
            ma = v;
            ret = k;
        }
    }

    int cnt{};
    for (int i{1}; i <= pos; ++i) {
        if (st[i].count(ret)) ++cnt;
    }

    cout << ret << " " << cnt;

    return 0;
}
