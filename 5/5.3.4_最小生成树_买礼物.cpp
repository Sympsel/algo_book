#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a, n;
int mat[N][N];
int dist[N];
bool st[N];

int prim() {
    fill(dist, dist + n + 1, a);
    dist[1] = a;
    int ret{};
    for (int i{1}; i <= n; ++i) {

        int t{1};
        for (int j{1}; j <= n; ++j)
            if (!st[j] && dist[j] < dist[t])
                t = j;

        st[t] = true;
        ret += dist[t];

        for (int j{1};j <= n; ++j)
            if (!st[j])
                dist[j] = min(dist[j], mat[t][j]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> n;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j) {
            cin >> mat[i][j];

            if (mat[i][j]) mat[i][j] = min(mat[i][j], a);
            else mat[i][j] = a;
        }
    }
    cout << prim() << "\n";

    return 0;
}
