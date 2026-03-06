#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double tar;
    cin >> n >> tar;
    cout << fixed << setprecision(1);
    double cur;
    while (n--) {
        cin >> cur;
        if (cur < tar) {
            cout << "On Sale! " << cur << "\n";
        }
    }

    return 0;
}