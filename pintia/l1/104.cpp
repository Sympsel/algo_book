#include <bits/stdc++.h>
using namespace std;

int a[9][9];
bool st[10];

void solve() {
    for (int i{}; i < 9; ++i) {
        memset(st, 0, sizeof st);
        for (int j{}; j < 9; ++j) {
            if (st[a[i][j]]) {
                cout << "0\n";
                return;
            }
            st[a[i][j]] = true;
        }
    }

    for (int i{}; i < 9; ++i) {
        memset(st, 0, sizeof st);
        for (int j{}; j < 9; ++j) {
            if (st[a[j][i]]) {
                cout << "0\n";
                return;
            }
            st[a[j][i]] = true;
        }
    }

    for (int i{}; i < 3; ++i) {
        for (int j{}; j < 3; ++j) {
            memset(st, 0, sizeof st);
            for (int u{}; u < 3; ++u) {
                for (int v{}; v < 3; ++v) {
                    if (st[a[i * 3 + u][j * 3 + v]]) {
                        cout << "0\n";
                        return;
                    }
                    st[a[i * 3 + u][j * 3 + v]] = true;
                }
            }
        }
    }
    cout << "1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        for (int i{}; i < 9; ++i)
            for (int j{}; j < 9; ++j)
                cin >> a[i][j];
        solve();
    }


    return 0;
}