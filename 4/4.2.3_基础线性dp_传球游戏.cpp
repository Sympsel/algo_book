#include <bits/stdc++.h>
using namespace std;

const int N = 31;
const int M = 31;
int f[N][M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    f[1][0] = 1;

    for (int j{1}; j <= m; ++j) {
        for (int i{1}; i <= n; ++i) {
            if (i == 1) f[i][j] = f[2][j - 1] + f[n][j - 1];
            else if (i == n) f[i][j] = f[1][j - 1] + f[n - 1][j - 1];
            else f[i][j] = f[i - 1][j - 1] + f[i + 1][j - 1];
        }
    }
    cout << f[1][m] << "\n";

    return 0;
}