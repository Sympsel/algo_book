#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[24];
    for (int i{}; i < 24; ++i) cin >> a[i];
    int x;
    while (cin >> x, x >= 0 && x < 24) {
        cout << a[x] << " ";
        if (a[x] > 50) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}