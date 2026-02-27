#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 3;
int a, b, p;
ll f[N], g[N];

ll qpow(ll a, ll b, ll p) {
    ll ret{1};
    while (b) {
        if (b & 1) ret = ret * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ret;
}

ll C(ll a, ll b, ll p) {
    if (b > a) return 0;
    return f[a] * g[b] % p * g[a - b] % p;
}

ll lucas(ll a, ll b, ll p) {
    if (b == 0) return 1;
    return lucas(a / p, b / p, p) * C(a % p, b % p, p) % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int T; cin >> T;
    while (T--) {
        cin >> a >> b >> p;
        int n{p - 1};
        f[0] = 1;
        for (int i{1}; i <= n; ++i) f[i] = f[i - 1] * i % p;
        g[n] = qpow(f[n], p - 2, p);
        for (int i{n - 1}; i >= 0; --i) g[i] = g[i + 1] * (i + 1) % p;
        cout << lucas(a + b, a, p) << "\n";
    }

    return 0;
}