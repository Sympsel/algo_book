#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll exgcd(ll a, ll b, ll& x0, ll& y0) {
    if (b == 0) {
        x0 = 1; y0 = 0;
        return a;
    }
    ll x, y;
    ll d{exgcd(b, a % b, x, y)};
    x0 = y;
    y0 = x - a / b * y;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    ll a{m - n}, b{l}, c{y - x};
    if (a < 0) {
        a = -a;
        c = -c;
    }

    ll x0, _;
    ll d{exgcd(a, b, x0, _)};
    if (c % d) {
        cout << "Impossible\n";
        return 0;
    }
    ll k1{b / d};
    x0 = c / d * x0;
    x0 = (x0 % k1 + k1) % k1;
    cout << x0 << "\n";
    return 0;
}