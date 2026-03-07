#include <bits/stdc++.h>
using namespace std;

const int M = 3e4 + 7;
const int N = 28;
int f[M];
int v[N], w[N];
int m, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i{1}; i <= m; ++i) {
        cin >> v[i] >> w[i];
        w[i] *= v[i];
    }

    for (int i{1}; i <= m; ++i) {
        for (int j{n}; j >= v[i]; --j) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[n] << "\n";

    return 0;
}
