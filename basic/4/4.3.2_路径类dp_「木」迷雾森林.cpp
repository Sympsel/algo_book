#include <bits/stdc++.h>
using namespace std;

const int p = 2333;
const int N = 3e3 + 5;
int n, m;
bool a[N][N];
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    f[n][0] = 1;
    bool x;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i{n}; i >= 1; --i) {
        for (int j{1}; j <= m; ++j) {
            if (!a[i][j]) {
                f[i][j] = (f[i + 1][j] + f[i][j - 1]) % p;
            }
        }
    }

    cout << f[1][m] << "\n";

    return 0;
}