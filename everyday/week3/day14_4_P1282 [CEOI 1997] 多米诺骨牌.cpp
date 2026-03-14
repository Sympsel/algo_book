#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1007;
int n;
int a[N];
const int M = 1e4 + 7;
int m = 5e3;
int f[M], g[M];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int x, y;
    for (int i{1}; i <= n; ++i) {
        cin >> x >> y;
        a[i] = x - y;
    }

    int* arr = f;
    int* brr = g;
    memset(f, 0x3f, sizeof f);
    f[m] = 0;

    for (int i{1}; i <= n; ++i) {
        for (int j{-m}; j <= m; ++j) {
            int x{arr[j - a[i] + m]};
            int y{arr[j + a[i] + m]};
            brr[j + m] = min(x, y + 1);
        }
        swap(arr, brr);
    }
    int ret{};
    for (int i{}; i <= m; ++i) {
        ret = min(arr[i + m], arr[-i + m]);
        if (ret != INF) {
            cout << ret << "\n";
            return 0;
        }
    }

    return 0;
}
