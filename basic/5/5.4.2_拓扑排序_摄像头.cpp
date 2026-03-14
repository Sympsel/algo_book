#include <bits/stdc++.h>
using namespace std;

const int M = 500;
int n;
vector<int> g[M + 5];
int in[M + 5];
bool st[M + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int id, m, _;
    for (int i{1}; i <= n; ++i) {
        cin >> id >> m;
        st[id] = true;
        while (m--) {
            cin >> _;
            g[id].emplace_back(_);
            ++in[_];
        }
    }

    queue<int> q;
    for (int i{1}; i <= M; ++i)
        if (st[i] && in[i] == 0)
            q.emplace(i);

    while (q.size()) {
        auto t{q.front()}; q.pop();
        for (auto _ : g[t]) {
            --in[_];
            if (st[_] && in[_] == 0)
                q.emplace(_);
        }
    }

    int cnt{};
    for (int i{1}; i <= M; ++i)
        if (st[i] && in[i])
            ++cnt;


    if (cnt == 0) cout << "YES\n";
    else cout << cnt << "\n";

    return 0;
}
