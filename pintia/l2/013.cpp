#include <bits/stdc++.h>
using namespace std;

const int N = 503;
const int M = 5e3 + 7;
int n, m;
int uf[N];
bool losted[N];
int fd(int x) {
    return x == uf[x] ? x : uf[x] = fd(uf[x]);
}

void un(int x, int y) {
    uf[fd(x)] = fd(y);
}

pair<int, int> ed[M];
bool st[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i{}; i < m; ++i) st[i] = true;
    for (int i{}; i < n; ++i) uf[i] = i;
    int total{};
    for (int i{}; i < m; ++i) {
        cin >> ed[i].first >> ed[i].second;
        un(ed[i].first, ed[i].second);
    }
    for (int i{}; i < n; ++i) {
        if (uf[i] == i) ++total;
    }

    int k; cin >> k;
    int cur, pre{total};
    for (int x{}; x < k; ++x) {
        cin >> cur;
        losted[cur] = true;
        // rm
        for (int i{}; i < m; ++i) {
            if (!st[i]) continue;
            auto [u, v]{ed[i]};
            if (cur == u || cur == v) st[i] = false;
        }

        // 计算联通分量
        for (int i{}; i < n; ++i) uf[i] = i;
        for (int i{}; i < m; ++i) {
            if (!st[i]) continue;
            auto [u, v]{ed[i]};
            un(u, v);
        }
        int cnt{};
        for (int i{}; i < n; ++i) {
            if (losted[i]) continue;
            if (uf[i] == i) ++cnt;
        }
        if (cnt <= pre) cout << "City " << cur << " is lost.\n";
        else cout << "Red Alert: City " << cur << " is lost!\n";
        pre = cnt;
    }
    if (k == n) cout << "Game Over.";
    return 0;
}
