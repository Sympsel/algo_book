#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1003;
using ll = long long;
ll f[N][N];
ll a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    memset(f, 0x3f, sizeof f);
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
        f[i][i] = 0;
    }

    for (int len{2}; len <= n; ++len) {
        for (int i{1}; len + i - 1 <= n; ++i) {
            int j{len + i - 1};
            for (int k{i}; k < j; ++k) {
                f[i][j] = min(f[i][k] + f[k + 1][j], f[i][j]);
            }
            f[i][j] += a[j] - a[i - 1];
        }
    }
    cout << f[1][n] << "\n";

    return 0;
}
