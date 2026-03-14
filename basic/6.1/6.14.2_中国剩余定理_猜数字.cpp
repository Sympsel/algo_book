#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 12;
int n;
int r[N], m[N];

ll qmul(ll a, ll b, ll p) {
    ll ret{};
    while (b) {
        if (b & 1) ret = (ret + a) % p;
        b >>= 1;
        a = (a + a) % p;
    }
    return ret;
}

void exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1; y = 0;
        return;
    }
    ll x1, y1;
    exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
}

ll crt() {
    ll ret{}, M{1};
    for (int i{1}; i <= n; ++i) M *= m[i];

    for (int i{1}; i <= n; ++i) {
        ll c{M / m[i]};
        ll x, _;
        exgcd(c, m[i], x, _);
        x = (x % m[i] + m[i]) % m[i];
        ret = ret + qmul(r[i], qmul(c, x, M), M);
        ret = (ret % M + M) % M;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> r[i];
    for (int i{1}; i <= n; ++i) cin >> m[i];

    cout << crt() << "\n";
    return 0;
}