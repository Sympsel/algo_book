#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int p = 998244353;
const int N = 5e6 + 7;
ll f[N], g[N];
int n;

ll qpow(ll a, ll b) {
    ll ret{1};
    while (b) {
        if (b & 1) ret = ret * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t >> n;

    f[0] = 1;
    for (int i{1}; i <= n; ++i)
        f[i] = f[i - 1] * i % p;
    g[n] = qpow(f[n], p - 2);
    for (int i{n - 1}; i >= 0; --i)
        g[i] = g[i + 1] * (i + 1) % p;

    int m;
    ll ret{};
    while (t--) {
        cin >> n >> m;
        ret ^= f[n] * g[m] % p * g[n - m] % p;
    }
    cout << ret << "\n";


    return 0;
}