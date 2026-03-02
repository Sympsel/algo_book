#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, m; char _;
    cin >> h >> _ >> m;
    if (h == 24) h = 0;
    if (h < 12 || (h == 12 && m == 0))
        cout << "Only "
        << setfill('0') << setw(2) << h
        << ":"<< setfill('0') << setw(2) << m
        << ".  Too early to Dang.";
    else {
        h -= 12;
        if (m != 0) h += 1;
        while (h--) {
            cout << "Dang";
        }
    }


    return 0;
}
