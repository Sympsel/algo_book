#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;
int f[N];
int n, a, b;
using ll = long long;

bool check(int x) {
    ll cnt{};
    for (int i{1}; i <= n; ++i) {
        if (f[i] <= x * a) continue;
        ll d{f[i] - x * a};
        cnt += (d + b - 1) / b;
        if (cnt > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b;
    for (int i{1}; i <= n; ++i) cin >> f[i];
    int l{}, r(5e5);
    while (l < r) {
        int mid{l + ((r - l) >> 1)};
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << "\n";

    return 0;
}