#include <bits/stdc++.h>
using namespace std;

const int N{12};
int n;
const double Z{1e-7};
double a[N][N];

bool zero(double num) {
    return fabs(num) < Z;
}

void gauss() {
    for (int i{1}; i <= n; ++i) {
        int aim{i};
        for (int j{1}; j <= n; ++j) {
            if (j < i && !zero(a[j][j])) continue;
            if (fabs(a[j][i]) > fabs(a[aim][i])) aim = j;
        }

        for (int j{1}; j <= n; ++j) swap(a[i][j], a[aim][j]);
        for (int j{n + 1}; j >= 1; --j) a[i][j] /= a[i][i];
        for (int j{1}; j <= n; ++j) {
            if (i == j) continue;
            double t{a[j][i]};
            for (int k{i}; k <= n + 1; ++k) a[j][k] -= t * a[i][k];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    double _{};
    for (int i{1}; i <= n; ++i) {
        cin >> a[0][i];
        _ += pow(a[0][i], 2);
    }

    for (int i{1}; i <= n; ++i) {
        double cur{};
        for (int j{1}; j <= n; ++j) {
            cin >> a[i][j];
            cur += pow(a[i][j], 2);
            a[i][j] -= a[0][j];
        }
        a[i][n + 1] = (cur - _) / 2;
    }

    gauss();

    cout << fixed << setprecision(3);
    for (int i{1}; i <= n; ++i)
        cout << a[i][n + 1] << " ";
    cout << "\n";

    return 0;
}