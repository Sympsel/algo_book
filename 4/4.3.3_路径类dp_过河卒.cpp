#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 30;
bool a[N][N];
ll f[N][N];
int n, m;
int dx[8]{-1, 1, -2, 2, -1, 1, -2, 2};
int dy[8]{-2, -2, 1, 1, 2, 2, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int x, y; cin >> x >> y;
    a[x][y] = true;
    for (int i{}; i < 8; ++i) {
        int r{x + dx[i]}, c{y + dy[i]};
        if (r >= 0 && c >= 0 && r <= n && c <= m)
            a[r][c] = true;
    }

    for (int i{}; i <= n && !a[i][0]; ++i)
        f[i][0] = 1;

    for (int i{1}; i <= m && !a[0][i]; ++i)
        f[0][i] = 1;

    for (int i{1}; i <= n; ++i)
        for (int j{1}; j <= m; ++j)
            if (!a[i][j])
                f[i][j] = f[i - 1][j] + f[i][j - 1];

    cout << f[n][m] << "\n";
    return 0;
}
