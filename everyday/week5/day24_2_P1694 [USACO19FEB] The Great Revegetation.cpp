#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 153;
int n, m;
vector<int> ed[N];
int ret[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int u, v;
    while (m--) {
        cin >> u >> v;
        ed[u].emplace_back(v);
        ed[v].emplace_back(u);
    }

    for (int u{1}; u <= n; ++u) {
        for (int i{1}; i <= 4; ++i) {
            bool flag{true};
            for (auto v : ed[u]) {
                if (ret[v] == i) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ret[u] = i;
                break;
            }
        }
    }
    for (int i{1}; i <= n; ++i) cout << ret[i];
    cout << "\n";


    return 0;
}
