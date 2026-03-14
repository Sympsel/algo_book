#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll exgcd(ll a, ll b, ll& x0, ll& y0) {
    if (b == 0) {
        x0 = 1; y0 = 0;
        return a;
    }

    ll x, y, g;
    g = exgcd(b, a % b, x, y);
    x0 = y;
    y0 = x - a / b * y;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    ll a, b, x0, y0;
    while (T--) {
        cin >> a >> b;
        ll g{exgcd(a, b, x0, y0)};
        // cout << g << "\n";
        if (g != 1) {
            cout << "-1\n";
            continue;
        }
        x0 = (x0 % b + b) % b;
        cout << x0 << "\n";
    }

    return 0;
}
