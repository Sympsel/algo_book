#include <bits/stdc++.h>
using namespace std;

const int N =   1e5 + 7;
int n, m, w;
int a[N];

int calc(int x) {
    int cnt{};
    int l{1}, r{1};
    while (r <= n) {
        while (r <= n && r - l + 1 <= w && a[r] - a[l] <= x) ++r;
        ++cnt;
        l = r;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> w;
    for (int i{1}; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + 1 + n);
    int l{}, r{a[n] - a[1]};
    while (l < r) {
        int mid{(r + l) / 2};
        if (calc(mid) <= m) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";

    return 0;
}
