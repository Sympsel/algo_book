#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 7;
int n, m;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i{n}; i >= 1; --i) {
        a[i] = a[i] - a[i - 1];
    }
    int x, y, z;
    while (m--) {
        cin >> x >> y >> z;
        a[x] += z; a[y + 1] -= z;
    }
    int min_{100};
    for (int i{1}; i <= n; ++i) {
        a[i] += a[i - 1];
        min_ = min(min_, a[i]);
    }
    cout << min_ << "\n";

    return 0;
}
