#include <bits/stdc++.h>
using namespace std;

const int N{53};
const double Z{1e-7};
int n;
double a[N][N];

inline bool zero(double num) {
    return fabs(num) < Z;
}

int gauss() {
    for (int i{1}; i <= n; ++i) {
        int aim{i};
        for (int j{1}; j <= n; ++j) {
            if (j < i && !zero(a[j][j])) continue;
            if (fabs(a[j][i]) > fabs(a[aim][i])) aim = j;
        }

        if (zero(a[aim][i])) continue;

        for (int j{1}; j <= n + 1; ++j) swap(a[aim][j], a[i][j]);

        for (int j{n + 1}; j >= i; --j) a[i][j] /= a[i][i];

        for (int j{1}; j <= n; ++j) {
            if (i == j) continue;
            double t{a[j][i]};
            for (int k{i}; k <= n + 1; ++k) a[j][k] -= t * a[i][k];
        }
    }

    int ret{1};
    for (int i{1}; i <= n; ++i) {
        if (zero(a[i][i]) && !zero(a[i][n + 1])) {
            ret = -1;
            break;
        }
        if (zero(a[i][i]))
            ret = 0;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{1}; i <= n; ++i)
        for (int j{1}; j <= n + 1; ++j)
            cin >> a[i][j];
    int ret{gauss()};

    if (ret == 1) {
        cout << fixed << setprecision(2);
        for (int i{1}; i <= n; ++i)
            cout << "x" << i << "=" << a[i][n + 1] << "\n";
    } else cout << ret << "\n";

    return 0;
}