#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    while (b) {
        int new_b{a % b};
        a = b;
        b = new_b;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int x, y;
    cin >> x;
    if (n == 1) {
        cout << abs(x) << "\n";
        return 0;
    }
    int c{abs(x)};
    while (--n) {
        cin >> y;
        c = gcd(c, abs(y));
    }
    cout << c << "\n";

    return 0;
}
