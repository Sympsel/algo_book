#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;
ll a[N];
int n, m;
int calc(ll x) {
    int cnt{};
    ll sum{};
    for (int i{1}; i <= n; ++i) {
        sum += a[i];
        if (sum > x) {
            ++cnt;
            sum = a[i];
        }
    }
    return cnt + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    ll l{}, r{};
    for (int i{1}; i <= n; ++i) {
        l = max(a[i], l);
        r += a[i];
    }

    while (l < r) {
        ll mid{l + ((r - l) >> 1)};
        if (calc(mid) <= m) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";

    return 0;
}
