#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int n;
int p[N];
int f[N][N];

int sumof(const int& i, const int& j) {
    return p[j] - p[i - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> p[i];
    memcpy(p + 1 + n, p + 1, sizeof(int) * n);
    for (int i{1}; i <= 2 * n; ++i)
        p[i] += p[i - 1];

    // 1.
    memset(f, 0x3f, sizeof f);
    for (int i{1}; i <= 2 * n; ++i) f[i][i] = 0;

    for (int len{1}; len <= n; ++len) {
        for (int i{1}; i + len - 1 <= 2 * n; ++i) {
            int j{i + len - 1};
            for (int k{i}; k < j; ++k)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sumof(i, j));
        }
    }
    int ret{0x3f3f3f3f};
    for (int i{1}; i <= n; ++i)
        ret = min(ret, f[i][i + n - 1]);
    cout << ret << "\n";

    // 2.
    memset(f, -0x3f, sizeof f);
    for (int i{1}; i <= 2 * n; ++i) f[i][i] = 0;

    for (int len{1}; len <= n; ++len) {
        for (int i{1}; i + len - 1 <= 2 * n; ++i) {
            int j{i + len - 1};
            for (int k{i}; k < j; ++k)
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + sumof(i, j));
        }
    }
    ret = -0x3f3f3f3f;
    for (int i{1}; i <= n; ++i)
        ret = max(ret, f[i][i + n - 1]);
    cout << ret << "\n";
    return 0;
}