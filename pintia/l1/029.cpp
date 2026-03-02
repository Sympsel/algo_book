#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h; cin >> h;
    h -= 100;
    cout << fixed << setprecision(1) << 1.f * h * 0.9 * 2;

    return 0;
}
