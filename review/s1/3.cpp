#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    for (int len{2}; len <= n; ++len) {
        for (int i{1}; i + len - 1 <= n; ++i) {
            int j{len + i - 1};
            if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
            else f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
        }
    }
    cout << f[1][n] << "\n";

    return 0;
}