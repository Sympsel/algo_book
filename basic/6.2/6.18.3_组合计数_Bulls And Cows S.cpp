#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
const int p = 5000011;
int n, k;
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

void init() {
    f[0] = 1;
    for (int i{1}; i <= n; ++i) {
        f[i] = i * f[i - 1] % p;
    }

    g[n] = qpow(f[n], p - 2);
    for (int i{n - 1}; i >= 0; --i) {
        g[i] = g[i + 1] * (i + 1) % p;
    }
}

ll C(ll a, ll b) {
    if (b == 0) return 1;
    if (b > a) return 0;
    return f[a] * g[b] % p * g[a - b] % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    init();

    ll ret{};
    for (int i{}; i <= n && n >= (i - 1) * k; ++i) {
        ret = (ret + C(n - (i - 1) * k, i)) % p;
    }
    cout << ret << "\n";
    return 0;
}
