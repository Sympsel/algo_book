#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i{}; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    int sz(a.size());
    if (sz < 2) {
        cout << "-1\n";
    } else if (sz == 2) {
        cout << a[1] % a[0] << "\n";
    } else {
        cout << max(a[sz - 3], a[sz - 1] % a[sz - 2]) << "\n";
    }

    return 0;
}
