#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n;
int a[N];
int f[N], g[N];

int main() {
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    for (int i{1}; i <= n; ++i) {
        f[i] = 1;
        for (int j{1}; j < i; ++j) {
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
        }
    }
    for (int i{n}; i >= 1; --i) {
        g[i] = 1;
        for (int j{n}; j > i; --j) {
            if (a[j] > a[i])
                g[i] = max(g[i], g[j] + 1);
        }
    }
    int _max{1};
    for (int i{1}; i <= n; ++i) {
        _max = max(f[i] + g[i] - 1, _max);
    }
    cout << (n - _max) << "\n";

    return 0;   
}
