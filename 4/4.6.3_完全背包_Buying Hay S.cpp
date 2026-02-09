#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 5e4 +5;
int f[M];
int a[N], b[N];
int n, m;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i{1}; i <= n; ++i) cin >> a[i] >> b[i];

    for (int i{1}; i <= n; ++i) {
        for (int j{}; j <= m; ++j) {
            f[j] = min(f[j], f[max(0, j - a[i])] + b[i]);
        }
    }
    cout << min(INF, f[m]) << "\n";

    return 0;
}