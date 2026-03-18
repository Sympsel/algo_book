#include <bits/stdc++.h>
using namespace std;
const int N = 504;
int n, a[N];
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    memset(f, 0x3f, sizeof f);
    for (int i{1}; i <= n; ++i) cin >> a[i];

    for (int i{1}; i <= n; ++i)
        f[i][i] = 1;

    for (int i{1}; i < n; ++i) {
        if (a[i] == a[i + 1]) f[i][i + 1] = 1;
        else f[i][i + 1] = 2;
    }

    for (int len{3}; len <= n; ++len) {
        for (int i{1}; i + len - 1 <= n; ++i) {
            int j{i + len - 1};
            for (int k{1}; k < j; ++k) {
                f[i][j] = min(f[i][k] + f[k + 1][j], f[i][j]);
            }
            if (a[i] == a[j]) f[i][j] = min(f[i][j], f[i + 1][j - 1]);
        }
    }
    cout << f[1][n] << "\n";

    return 0;
}