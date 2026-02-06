#include <bits/stdc++.h>
using namespace std;

const int N = 11;

int n;
int a[N][N];
int f[2 * N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int x, y;
    while (cin >> x >> y, x || y)
        cin >> a[x][y];
    // 读取并丢弃最后不合条件多余的0
    cin >> x;
    for (int s{2}; s <= 2 * n; ++s) {
        for (int i1{1}; i1 <= n; ++i1) {
            for (int i2{1}; i2 <= n; ++i2) {
                int j1{s - i1}, j2{s - i2};
                if (j1 < 1 || j2 < 1 || j1 > n || j2 > n) continue;
                int& t{f[s][i1][i2]};
                t = max(t, f[s - 1][i1][i2]);
                t = max(t, f[s - 1][i1 - 1][i2]);
                t = max(t, f[s - 1][i1][i2 - 1]);
                t = max(t, f[s - 1][i1 - 1][i2 - 1]);
                if (i1 ==i2) t += a[i1][j1];
                else t += a[i1][j1] + a[i2][j2];
            }
        }
    }
    return 0;
}
