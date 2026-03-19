#include <bits/stdc++.h>
using namespace std;

int n, k;
const int N = 1e4 + 7;
using ll = long long;
ll a[N];
ll f[N];
ll ret{};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i{1}; i <= n; ++i) cin >> a[i];

    for (int i{1}; i <= n; ++i) {
        ll ma{a[i]};
        for (int j{i - 1}; j >= 0 && i - j <= k; --j) {
            f[i] = max(f[j] + (i - j) * ma, f[i]);
            ma = max(ma, a[j]);
        }
    }
    cout << f[n] << "\n";
    return 0;
}
