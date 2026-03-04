#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n, m;
int a[N], d[N], s[N], t[N], f[N];

bool check(int x) {
    for (int i{1}; i <= n; ++i) f[i] = a[i] - a[i - 1];
    for (int i{1}; i <= x; ++i) {
        f[s[i]] -= d[i];
        f[t[i] + 1] += d[i];
    }
    for (int i{1}; i <= n; ++i) {
        f[i] += f[i - 1];
        if (f[i] < 0) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    for (int i{1}; i <= m; ++i) cin >> d[i] >> s[i] >> t[i];
    int l{1}, r{m};
    while (l < r) {
        int mid{l + ((r - l) >> 1)};
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (check(l)) {
        cout << "-1\n" << l << "\n";
    } else {
        cout << "0\n";
    }

    return 0;
}
