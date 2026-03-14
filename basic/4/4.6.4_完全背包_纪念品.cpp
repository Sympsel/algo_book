#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1e4 + 5;
int d, n, m;
int p[N][N];
int f[M];

void solve(int* v, int* w, int& m) {
    memset(f, 0, sizeof f);

    for (int i{1}; i <= n; ++i) {
        for (int j{v[i]}; j <= m; ++j) {
            f[j] = max(f[j], f[j - v[i]] + w[i] - v[i]);
        }
    }
    // 当日利润->下一日的本金
    m += f[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> d >> n >> m;
    for (int i{1}; i <= d; ++i)
        for (int j{1}; j <= n; ++j)
            cin >> p[i][j];

    for (int i{1}; i < d; ++i) {
        solve(p[i], p[i + 1], m);
    }
    cout << m << "\n";

    return 0;
}