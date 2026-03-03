#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
int n, m;
int uf[N];
int c[N], v[N];
int f[N];

int fd(int x) {
    return uf[x] == x ? x : uf[x] = fd(uf[x]);
}

void init() {
    int q;
    cin >> n >> q >> m;
    for (int i{1}; i <= n; ++i) {
        cin >> c[i] >> v[i];
        uf[i] = i;
    }
    int x, y;
    while (q--) {
        cin >> x >> y;
        uf[fd(x)] = fd(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    for (int i{1}; i <= n; ++i) {
        if (uf[i] != i) {
            int root{fd(i)};
            c[root] += c[i];
            v[root] += v[i];
            c[i] = v[i] = 0;
        }
    }

    for (int i{1}; i <= n; ++i) {
        if (c[i] == 0) continue;
        for (int j{m}; j >= c[i]; --j) {
            f[j] = max(f[j], f[j - c[i]] + v[i]);
        }
    }
    cout << f[m] << "\n";
    return 0;
}
