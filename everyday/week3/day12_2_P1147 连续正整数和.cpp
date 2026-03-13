#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x; cin >> x;
    for (ll len{x}; len >= 2; --len) {
        for (ll i{1}; i <= x; ++i) {
            ll cur{(i + i + len - 1) * len / 2};
            if (cur == x) {
                cout << i << " " << i + len - 1 << "\n";
                break;
            } else if (cur > x) {
                break;
            } else {}
        }
    }

    return 0;
}
