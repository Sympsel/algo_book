#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
using ll = long long;
ll a[N];
ll n, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (int i{1}; i <= n; ++i) cin >> a[i];

    ll ret{};
    for (int i{1}; i < n; ++i) {
        if (a[i] + a[i + 1] <= x) continue;
        if (a[i] >= x) {
            ret += a[i] - x + a[i + 1];
            a[i + 1] = 0;
        } else if (a[i] < x) {
            ll t{a[i] + a[i + 1] - x};
            ret += t;
            a[i + 1] -= t;
        }
    }
    cout << ret << "\n";

    return 0;
}
