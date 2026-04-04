#include <bits/stdc++.h>
using namespace std;

using ll =long long;
const int N = 1e5 + 7;
ll n, m;
ll a[N];
ll b[N];
ll c[N];

int main() {
    cin >> n >> m;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll ret = 1e18;
    for (int i{1}; i + m - 1 <= n; ++i) {
        ret = min(ret, a[i + m - 1] * a[i + m - 1] - a[i] * a[i]);
    }
    cout << ret << "\n";
    return 0;
}