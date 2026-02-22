#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll a, b;

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x0, y0;
    ll g{exgcd(b, a % b, x0, y0)};
    x = y0;
    y = x0 - a / b * y0;
    return g;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    ll x0, y0, g;
    while (T--) {
        cin >> a >> b;
        g = exgcd(a, b, x0, y0);
        if (g != 1) {
            cout << "-1\n";
            continue;
        }

        x0 = (x0 % b + b) % b;
        cout << x0 << "\n";
    }

    return 0;
}