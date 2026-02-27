#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b) {
        ll new_b{a % b};
        a = b;
        b = new_b;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m; ++n; ++m;
    ll t{n * m};
    ll ret{t * (t - 1) * (t - 2) / 6};
    ret -= n * m * (m - 1) * (m - 2) / 6;
    ret -= m * n * (n - 1) * (n - 2) / 6;
    for (int i{2}; i < n; ++i) {
        for (int j{2}; j < m; ++j) {
            ret -= 2ll * (n - i) * (m - j) * (gcd(i, j) - 1);
        }
    }
    cout << ret << "\n";

    return 0;
}