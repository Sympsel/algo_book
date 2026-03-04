#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int y, m, d; char _;
    cin >> m >> _ >> d >> _ >> y;
    cout << setfill('0');
    cout << y << _ << setw(2) << m << _ << setw(2) << d;

    return 0;
}
