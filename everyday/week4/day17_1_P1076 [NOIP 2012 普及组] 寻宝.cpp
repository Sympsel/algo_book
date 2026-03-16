#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
const int M = 103 + 7;
const int p = 20123;
using ll = long long;
pair<ll, bool> a[N][M];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    bool st; ll x;
    for (int i{1}; i <= n; ++i) {
        for (int j{}; j < m; ++j) {
            cin >> st >> x;
            a[i][j] = {x, st};
        }
    }
    for (int i{1}; i <= n; ++i) {
        for (int j{}; j < m; ++j) {
            cout << a[i][j].first << " \n"[j == m - 1];
        }
    }
    int begin; cin >> begin;

    ll ret{};
    int j{begin};
    for (int i{1}; i <= n; ++i) {

        int cnt{};
        auto [move, has]{a[i][j]};
        // cout << "has: " << has << " move: " << move << "\n";
        ret = (ret + move) % p;
        // cout << "ret: " << ret << "\n";
        while (cnt <= move) {
            // cout << "a: " << a[i][j].first << "\n";
            if (has) ++cnt;
            j = j + 1 > m - 1 ? 0 : j + 1;
            has = a[i][j].first;
            // move = a[i][j].second;
        }
        // ret = (ret + a[i][j].first) % p;
        // cout << begin << "\n";
        j = j - 1 < 0 ? m - 1 : j - 1;
        // cout << "j: " << j << "\n";
    }
    cout << ret << "\n";
    return 0;
}