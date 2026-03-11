#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll y, z;
    cin >> y >> z;
    ll x{y + 100000000000};
    if (x >= z) {
        cout << (x - z) << "\n";
    } else {
        z %= 1000000;
        ll ret{abs(y - z)};
        cout << (ret >= 500000 ? 1000000 - ret : ret) << "\n";
    }

    return 0;
}