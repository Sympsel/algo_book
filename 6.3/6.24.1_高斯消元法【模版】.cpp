#include <bits/stdc++.h>
using namespace std;

const int N(1e2 + 3);
const double Z{1e-7};

int n;
double a[N][N];

bool zero(const double& num) {
    return fabs(num) < Z;
}

bool gauss() {

    for (int i{1}; i <= n; ++i) {
        int aim{i};
        for (int j{1}; j <= n; ++j) {
            if (j < i && !zero(a[j][j])) continue;
            if (fabs(a[j][i]) > fabs(a[aim][i]))
                aim = j;
        }

        if (zero(a[aim][i])) continue;

        for (int j{1}; j <= n + 1; ++j) swap(a[aim][j], a[i][j]);

        for (int j{n + 1}; j >= i; --j) a[i][j] /= a[i][i];

        for (int j{1}; j <= n; ++j) {
            if (i == j) continue;
            // double t{a[j][i] / a[i][i]};
            double t{a[j][i];
            for (int k{i}; k <= n + 1; ++k) a[j][k] -= t * a[i][k];
        }
    }

    bool ret{true};
    for (int i{1}; i <= n; ++i) {
        if (zero(a[i][i])) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{1}; i <= n; ++i)
        for (int j{1}; j <= n + 1; ++j)
            cin >> a[i][j];

    bool ret{gauss()};
    if (!ret) {
        cout << "No Solution\n";
        return 0;
    }
    cout << fixed << setprecision(2);
    for (int i{1}; i <= n; ++i) {
        cout << a[i][n + 1] << "\n";
    }

    return 0;
}
