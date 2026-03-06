#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<bool> a(n + 1, false);
    vector<bool> b(m + 1, false);
    bool type; int x;
    while (q--) {
        cin >> type >> x;
        if (type) {
            b[x] = true;
        } else {
            a[x] = true;
        }
    }
    int r{}, c{};
    for (int i{1}; i <= n; ++i)
        if (!a[i]) ++r;
    for (int i{1}; i <= m; ++i)
        if (!b[i]) ++c;
    cout << (1ll * r * c);

    return 0;
}