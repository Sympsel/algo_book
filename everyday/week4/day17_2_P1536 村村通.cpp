#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n;
int uf[N];
int fd(int x) {
    return x == uf[x] ? x : uf[x] = fd(uf[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    while (cin >> n >> m) {
        for (int i{1}; i <= n; ++i) uf[i] = i;
        int u, v;
        while (m--) {
            cin >> u >> v;
            uf[fd(u)] = fd(v);
        }

        int ret{};
        for (int i{1}; i <= n; ++i)
            if (uf[i] == i) ++ret;
        cout << ret - 1 << "\n";
    }

    return 0;
}
