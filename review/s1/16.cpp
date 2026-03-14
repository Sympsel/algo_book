#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n;
int fa[N];

int fd(int x) {
    return x == fa[x] ? x : fd(fa[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; cin >> n >> m;
    for (int i{1}; i <= n; ++i) fa[i] = i;
    int op, x, y;
    while (m--) {
        cin >> op >> x >> y;
        int fx{fd(x)}, fy{fd(y)};
        if (op == 2) {
            if (fx == fy)
                cout << "Y\n";
            else cout << "N\n";
        } else if (op == 1) {
            fa[fx] = fy;
        } else {}
    }

    return 0;
}