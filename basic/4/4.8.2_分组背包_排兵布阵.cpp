#include <bits/stdc++.h>
using namespace std;

const int N = 105;
// 第一维城堡编号，第二维其它玩家数量
int p[N][N];
const int M = 2e4 + 5;
int s, n, m;
int f[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> n >> m;
    int _;
    for (int i{1}; i <= s; ++i) {
        for (int j{1}; j <= n; ++j) {
            cin >> _;
            p[j][i] = _ * 2 + 1;
        }
    }

    for (int i{1}; i <= n; ++i) sort(p[i] + 1, p[i] + s + 1);

    for (int i{1}; i <= n; ++i) {
        for (int j{m}; j >= 0; --j) {
            for (int k{1}; k <= s && j >= p[i][k]; ++k) {
                f[j] = max(f[j], f[j - p[i][k]] + k * i);
            }
        }
    }
    cout << f[m] << "\n";

    return 0;
}
