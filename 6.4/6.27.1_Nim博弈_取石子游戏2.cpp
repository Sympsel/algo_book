#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int s{}, _;
    while (n--) {
        cin >> _;
        s ^= _;
    }

    if (s) cout << "win" << endl;
    else cout << "lose" << endl;

    return 0;
}