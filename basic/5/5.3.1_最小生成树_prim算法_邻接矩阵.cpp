#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 5005;
const int M = 2e5 + 5;
int n, m;
int mat[N][N];
int dist[N];
bool st[N];

int prim() {
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;
    int ret{};
    for (int i{1}; i <= n; ++i) {
        int t{};
        for (int j{1}; j <= n; ++j)
            if (!st[j] && dist[j] < dist[t])
                t = j;

        if (dist[t] == INF) return INF;
        st[t] = true;
        ret += dist[t];

        for (int j{1}; j <= n; ++j) {
            if (!st[j])
                dist[j] = min(dist[j], mat[t][j]);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int u, v, w;
    for (int i{1}; i <= n; ++i)
        fill(mat[i], mat[i] + n + 1, INF);

    for (int i{1}; i <= m; ++i) {
        cin >> u >> v >> w;
        // 使用min防止重边出现
        mat[u][v] = mat[v][u] = min(mat[u][v], w);
    }

    int ret = prim();
    if (ret == INF) cout << "orz\n";
    else cout << ret << "\n";
    return 0;
}
