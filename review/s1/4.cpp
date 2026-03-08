#include <bits/stdc++.h>
using namespace std;

const int N = 2003;
int n;
int a[N];
using ll = long long;
ll f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];

    for (int len{1}; len <= n; ++len) {
        for (int i{1}; len + i - 1 <= n; ++i) {
            int j{i + len - 1};
            f[i][j] = max(f[i + 1][j] + a[i] * (n - len + 1), f[i][j - 1] + a[j] * (n - len + 1));
        }
    }
    cout << f[1][n] << "\n";

    return 0;
}
