#include <bits/stdc++.h>
using namespace std;

const int N = 250;
int n;
int a[N];
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        f[i][i] = a[i];
    }

    for (int len{2}; len <= n; ++len) {
        for (int i{1}; i + len - 1 <= n; ++i) {
            int j{i + len - 1};
            for (int k{i}; k < j; ++k) {
                if (f[i][k] > 0 && f[i][k] == f[k + 1][j])
                    f[i][j] = max(f[i][j], f[i][k] + 1);
            }
        }
    }
    int ret{};
    for (int i{1}; i <= n; ++i)
        for (int j{1}; j <= n; ++j)
            ret = max(ret, f[i][j]);
    cout << ret << "\n";
    return 0;
}