#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
const int M = 503;
int n, tar;
int a[N]; // 库存
int b[N]; // 售价
double c[N]; // 单价
double f[N][M];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> tar;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    for (int i{1}; i <= n; ++i) {
        cin >> b[i];
        c[i] = 1.f * b[i] / a[i];
    }

    for (int i{1}; i <= n; ++i) {
        for (int j{}; j <= n; ++j) {
            for (int k{}; k * c[i] <= a[i]; ++k) {
                f[i][j] = f[i - 1][j];
                if () {
                    f[i][j] = max(f[i - 1][j], f[i - 1][j - ])
                }
            }
        }
    }

    return 0;
}