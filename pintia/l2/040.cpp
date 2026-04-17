#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 7;
int cur{1};
vector<int> ed[N];
int pos;
int saves[103];

int main() {
    cin >> n >> m;
    for (int u{1}; u <= n; ++u) {
        int sz; cin >> sz;
        while (sz--) {
            int v; cin >> v;
            ed[u].emplace_back(v);
        }
    }
    while (m--) {
        int op, ch; cin >> op >> ch;
        if (op == 1) {
            saves[ch] = cur;
            cout << cur << "\n";
        } else if (op == 0) {
            cur = ed[cur][ch - 1];
        } else if (op == 2) {
            cur = saves[ch];
        } else {}
    }
    cout << cur;
    return 0;
}
