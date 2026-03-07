#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool has;
    int col;
    cin >> col >> has;
    if (col == 2) {
        cout << "-\nstop";
    } else {
        if (has) {
            if (col == 1) cout << "-\nmove";
            else cout << "-\nstop";
        } else {
            if (col == 1) cout << "dudu\nmove";
            else cout << "biii\nstop";
        }
    }

    return 0;
}