#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], n;
int f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    for (int i{1}; i <= n; ++i) {
        f[i] = a[i] + max(0, f[i - 1]);
    }
    int ret{-0x3f3f3f3f};
    for (int i{1}; i <= n; ++i) {
        ret = max(ret, f[i]);
    }
    cout << ret << "\n";

    return 0;
}