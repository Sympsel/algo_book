#include <bits/stdc++.h>
using namespace std;

int mp[25] = {
    -1, -1, -1, -1, -1, -1, 10000,
    36, 720, 360, 80, 252, 108,
    72, 54, 180, 72, 180, 119,
    36, 306, 1080, 144, 1800, 3600
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[4][4];
    int _{};
    int _i{}, _j{};
    for (int i{1}; i <= 3; ++i) {
        for (int j{1}; j <= 3; ++j) {

            cin >> a[i][j];
            if (a[i][j] == 0) {
                _i = i; _j = j;
            } else {
                _ += a[i][j];
            }
        }
    }
    a[_i][_j] = 45 - _;
    int _a, _b;
    for (int i{}; i < 3; ++i) {
        cin >> _a >> _b;
        cout << a[_a][_b] << "\n";
    }

    int x; cin >> x;
    int ret{};
    if (x > 6) {
        if (x == 7) {
            ret += a[1][1] + a[2][2] + a[3][3];
        } else {
            ret += a[3][1] + a[2][2] + a[1][3];
        }
    } else if (x > 3) {
        for (int i{1}; i <= 3; ++i) {
            ret += a[i][x - 3];
        }
    } else {
        for (int i{1}; i <= 3; ++i) {
            ret += a[x][i];
        }
    }

    cout << mp[ret];
    return 0;
}
