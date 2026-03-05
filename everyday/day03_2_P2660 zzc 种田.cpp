#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll ret{};
void gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    while (y) {
        ret += 4 * y * (x / y);
        ll new_b{x % y};
        x = y;
        y = new_b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y;
    cin >> x >> y;
    gcd(x, y);
    cout << ret << "\n";

    return 0;
}