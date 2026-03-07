#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5 + 7;
int n;
ll a[N];
ll t[N];

ll merge(int b, int e) {
    if (b >= e) return 0;
    ll mid{b + ((e - b) >> 1)};
    ll ret{merge(b, mid) + merge(mid + 1, e)};
    ll i{b}, j{mid + 1}, k{b};
    while (i <= mid && j <= e) {
        if (a[i] <= a[j]) {
            t[k++] = a[i++];
        } else {
            ret += mid + 1 - i;
            t[k++] = a[j++];
        }
    }

    while (i <= mid)
        t[k++] = a[i++];
    while (j <= e)
        t[k++] = a[j++];
    for (ll i{b}; i <= e; ++i) a[i] = t[i];
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{}; i < n; ++i) cin >> a[i];

    ll cnt{merge(0, n - 1)};
    cout << cnt << "\n";
    return 0;
}
