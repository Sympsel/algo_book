#include <bits/stdc++.h>
using namespace std;

using ll = long long;
bool check(ll x) {
    if (x <= 2) return false;
    int i = 2;
    while (x && i <= x / i) {
        while (x % i == 0) {
            if (i % 2 == 0) return false;
            x /= i;
        }
        ++i;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; ll x;
    cin >> T;
    while (T--) {
        cin >> x;
        if (check(x)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
