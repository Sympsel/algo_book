#include <iostream>
using namespace std;

string s1, s2;
const int N = 2e3 + 10;
int f[N][N];

int main() {
    cin >> s1 >> s2;
    int n(s1.size()), m(s2.size());

    for (int i{1}; i <= m; ++i) {
        f[0][i] = i;
    }
    for (int i{1}; i <= n; ++i) {
        f[i][0] = i;
    }

    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                f[i][j] = f[i - 1][j - 1];
            } else {
                f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
            }
        }
    }
    cout << f[n][m] << "\n";
    return 0;
}