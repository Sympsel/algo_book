#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    int n;
    while (t--) {
        cin >> n;
        if (n % 6) cout << "October wins!" << endl;
        else cout << "Roy wins!" << endl;
    }

    return 0;
}