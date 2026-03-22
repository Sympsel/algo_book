#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
const int M = 1010;
const int INF = 0x3f3f3f3f;
int n, m, k;
int f[N][M];
int a[N], b[N];
pair<int, int> c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    memset(f, 0x3f, sizeof f);
    for (int i{}; i <= m; ++i) f[0][i] = 0;
    for (int i{1}; i <= n; ++i)
        cin >> a[i] >> b[i];
    int p, l, h;
    for (int i{1}; i <= k; ++i) {
        cin >> p >> l >> h;
        c[p] = {l, h};
    }

    for (int i{1}; i <= n; ++i) {
        for (int j{}; j <= m; ++j) {
            if (f[i][j] == -1) continue;
            if (j >= b[i] && f[i - 1][j - b[i]] != -1) {
                f[i][j] = f[i - 1][j - b[i]];
            }
            for (int k{1}; k <= )
        }
    }



    return 0;
}