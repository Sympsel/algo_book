#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
int n;
vector<int> edges[N];
bool st[N];

void dfs(int root) {
    cout << root << " ";
    st[root] = true;
    for (auto _ : edges[root]) {
        if (st[_]) continue;
        dfs(_);
    }
}

void bfs(int root) {
    queue<int> q;
    st[root] = true;
    q.emplace(root);

    while (q.size()) {
        auto t{q.front()}; q.pop();
        cout << t << " ";
        for (auto _ : edges[t]) {
            if (st[_]) continue;
            st[_] = true;
            q.emplace(_);
        }
    }
}

int main() {
    cin >> n;
    int x, y;
    for (int i{1}; i < n; ++i) {
        cin >> x >> y;
        edges[x].emplace_back(y);
        edges[y].emplace_back(x);
    }

    dfs(1);
    cout << "\n";
    memset(st, 0, sizeof st);
    bfs(1);
    cout << "\n";
    return 0;
}
