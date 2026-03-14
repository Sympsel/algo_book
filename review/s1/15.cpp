#include <bits/stdc++.h>
using namespace std;

const int N = 103;
const int M = 1e4 + 7;
int n, m;
using ll = long long;
ll f[N][N];
int path[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i{1}; i <= m; ++i) cin >> path[i];

    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j) {
            cin >> f[i][j];
        }
    }

    for (int k{1}; k <= n; ++k) {
        for (int i{1}; i <= n; ++i) {
            for (int j{1}; j <= n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    ll ret{};
    for (int i{1}; i < m; ++i) {
        ret += f[path[i]][path[i + 1]];
    }
    cout << ret << "\n";


    return 0;
}