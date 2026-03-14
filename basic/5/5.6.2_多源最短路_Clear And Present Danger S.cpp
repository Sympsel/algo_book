#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 10005;
int f[N][N];
int seq[M];
int n, m;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i{1}; i <= m; ++i)
        cin >> seq[i];
    for (int i{1}; i <= n; ++i)
        for (int j{1}; j <= n; ++j)
            cin >> f[i][j];

    for (int k{1}; k <= n; ++k)
        for (int i{1}; i <= n; ++i)
            for (int j{1}; j <= n; ++j)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

    ll ret{};
    for (int i{1}; i < m; ++i)
        ret += f[seq[i]][seq[i + 1]];
    cout << ret << "\n";

    return 0;
}