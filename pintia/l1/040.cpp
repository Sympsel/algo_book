#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    char g; double x;
    cout << fixed << setprecision(2);
    while (t--) {
        cin >> g >> x;
        if (g == 'M') cout << x / 1.09 << "\n";
        else cout << x * 1.09 << "\n";
    }

    return 0;
}
