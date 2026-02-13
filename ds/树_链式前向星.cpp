#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int h[N];
int e[N * 2], ne[N * 2];
int id;
bool st[N];
int n;

void add(int x, int y) {
        ++id;
        e[id] = y;
        ne[id] = h[x];
        h[x] = id;
}

void dfs(int root) {
    cout << root << " ";
    st[root] = true;
    for (int i{h[root]}; i; i = ne[i]) {
        int v{e[i]};
        if (st[v]) continue;
        dfs(v);
    }
}

void bfs(int root) {
    queue<int> q;
    q.emplace(root);
    st[root] = true;

    while (q.size()) {
        auto t{q.front()}; q.pop();
        cout << t << " ";
        for (int i{h[t]}; i; i = ne[i]) {
            int v{e[i]};
            if (st[v]) continue;
            q.emplace(v);
            st[v] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int x, y;
    for (int i{1}; i < n; ++i) {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }

    dfs(1);
    cout << "\n";
    memset(st, 0, sizeof st);
    bfs(1);
    cout << "\n";

    return 0;
}
