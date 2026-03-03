#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;
    cout << fixed << setprecision(2);
    if (y == 0) cout << x << "/0=Error";
    else if (y < 0) cout << x << "/(" << y << ")=" << 1.0f * x / y;
    else cout << x << "/" << y << "=" << 1.0f * x / y;

    return 0;
}
