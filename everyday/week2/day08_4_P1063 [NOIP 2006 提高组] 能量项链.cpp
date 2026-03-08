#include <bits/stdc++.h>
using namespace std;

const int N = 203;
int n;
int a[N];

int f[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    memcpy(a + 1 + n, a + 1, sizeof(int) * n);

    for (int len{3}; len <= n + 1; ++len) {
        for (int i{1}; i + len - 1 <= 2 * n; ++i) {
            int j{i + len - 1};
            for (int k{i + 1}; k < j; ++k) {
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[j] * a[k]);
            }
        }
    }
    int ret{};
    for (int i{1}; i <= n; ++i) {
        ret = max(ret, f[i][i + n]);
    }
    cout << ret << "\n";

    return 0;
}
