#include <bits/stdc++.h>
using namespace std;

const int N = 203;
int n;
int a[N];
int s[N];
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int _;
    memset(f, 0x3f, sizeof f);
    for (int i{1}; i <= n; ++i) {
        cin >> _; a[i] = a[i + n] = _;
        f[i][i] = f[i + n][i + n] = 0;
    }
    for (int i{1}; i <= 2 * n; ++i)
        s[i] = a[i] + s[i - 1];

    for (int len{1}; len <= n; ++len) {
        for (int i{1}; i + len - 1 <= 2 * n; ++i) {
            int j{len + i - 1};
            for (int k{i}; k < j; ++k) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
            // f[i][j] +=s[j] - s[i - 1];
        }
    }

    int ret{0x3f3f3f3f};
    for (int i{1}; i <= n; ++i) {
        ret = min(ret, f[i][i + n - 1]);
    }
    cout << ret << "\n";
    memset(f, 0, sizeof f);
    for (int len{1}; len <= n; ++len) {
        for (int i{1}; i + len - 1 <= 2 * n; ++i) {
            int j{len + i - 1};
            for (int k{i}; k < j; ++k) {
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }

            // f[i][j] += s[j] - s[i - 1];
        }
    }
    ret = 0;
    for (int i{1}; i <= n; ++i) {
        ret = max(ret, f[i][i + n - 1]);
    }
    cout << ret << "\n";

    return 0;
}