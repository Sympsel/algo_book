#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 4;
const int p = 1e5 + 3;
using ll = long long;
ll f[N], g[N];

ll qpow(ll a, ll b) {
    ll ret{1};
    while (b) {
        if (b & 1) ret = ret * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ret;
}

ll C(ll a, ll b) {
    if (b > a) return 0;
    return f[a] * g[b] % p * g[a - b] % p;
}

void init() {
    int n(2e3);
    f[0] = 1;
    for (int i{1}; i <= n; ++i) f[i] = f[i - 1] * i % p;
    g[n] = qpow(f[n], p - 2);
    for (int i{n - 1}; i >= 0; --i) g[i] = g[i + 1] * (i + 1) % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int a, b, c, d; cin >> a >> b >> c >> d;
    int k; cin >> k;
    ll ret{};
    for (int i{}; i <= k; ++i) {
        ret = (ret + C(d, i)
            * C(c, i) % p
            * f[i] % p
            * C(b + d - i, k - i) % p
            * C(a, k - i) % p
            * f[k - i]) % p;
    }
    ret = (ret % p + p) % p;
    cout << ret << "\n";

    return 0;
}
