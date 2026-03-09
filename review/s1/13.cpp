#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int f[N];
    int pmin{0};
    ll ret(-1e16);
    for (int i{1}; i <= n; ++i) {
        cin >> f[i];
        f[i] += f[i - 1];
        ret = max(ret, 1ll * (f[i] - pmin));
        pmin = min(f[i], pmin);
    }
    cout << ret << "\n";

    return 0;
}