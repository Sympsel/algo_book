#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 7;
using ll = long long;
ll n, k;

ll a[N];
ll f[N], g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    for (ll i{1}, j{1}; j <= n; ++j) {
        while (a[j] - a[i] > k) {
            ++i;
        }
        f[j] = max(f[i - 1], j - i + 1);
    }

    for (ll i{n}, j{n}; i >= 1; --i) {
        while (a[j] - a[i] > k) {
            --j;
        }
        g[i] = max(g[i + 1], j - i + 1);
    }

    ll ret{};
    for (ll i{2}; i <= n - 1; ++i) {
        ret = max(ret, f[i] + g[i + 1]);
    }
    cout << ret << "\n";

    return 0;
}