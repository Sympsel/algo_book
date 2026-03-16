#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
const int M = 33;
int n, m;
int a[N];
int f[N][M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n  >> m;
    int _;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i{1}; i <= n; ++i) {
        for (int j{}; j <= m; ++j) {
            int c{};
            if (j % 2 == 1 && a[i] == 2 || j % 2 == 0 && a[i] == 1) {
                ++c;
            }
            f[i][j] = f[i - 1][j] + c;
            if (j) f[i][j] = max(f[i][j], f[i - 1][j - 1] + c);
        }
    }

    int ret{};
    for (int i{1}; i <= m; ++i) {
        ret = max(ret, f[n][i]);
    }
    cout << ret << "\n";

    return 0;
}
