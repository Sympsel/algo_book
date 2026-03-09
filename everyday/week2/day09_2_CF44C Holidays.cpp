#include <bits/stdc++.h>
using namespace std;

int a[103];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int m; cin >> m;
    int l, r;
    while (m--) {
        cin >> l >> r;
        ++a[l];
        --a[r + 1];
    }
    for (int i{1}; i <= n; ++i) {
        a[i] += a[i - 1];
        if (a[i] != 1) {
            cout << i << " " << a[i];
            return 0;
        }
    }
    cout << "OK\n";

    return 0;
}