#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int n;
int p[N];
int f[N][N];

void init() {
    cin >> n;
    for (int i{1}; i <= n; ++i) {
        cin >> p[i];
        p[i] += p[i - 1];
    }
    memset(f, 0x3f, sizeof f);
    for (int i{1}; i <= n; ++i) f[i][i] = 0;
}

int sumof(const int& i, const int& j) {
    return p[j] - p[i - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for (int len{1}; len <= n; ++len) {
        for (int i{1}; i + len - 1 <= n; ++i) {
            int j{i + len - 1};
            int& ret{f[i][j]};
            for (int k{i}; k < j; ++k) {
                ret = min(ret, f[i][k] + f[k + 1][j] + sumof(i, j));
            }
        }
    }
    cout << f[1][n] << "\n";

    return 0;
}
