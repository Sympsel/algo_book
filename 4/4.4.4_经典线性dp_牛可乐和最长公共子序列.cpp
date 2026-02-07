#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 4;
string s1, s2;
int f[N][N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2;
    int n(s1.size()), m(s2.size());
    if (!n || !m) {
        cout << "0\n";
        return 0;
    }

    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }

        }
    }
    cout << f[n][m] << "\n";

    return 0;
}
