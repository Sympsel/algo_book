#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
const int N = 1005;
const int INF = 0x3f3f3f3f;
int f[N];

int sg(int x) {
    if (f[x] != INF) return f[x];
    unordered_set<int> mp;
    for (auto& _ : b)
        if (x - _ >= 0)
            mp.emplace(sg(x - _));
    int mex{};
    while (mp.count(mex)) ++mex;
    return f[x] = mex;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(f, 0x3f, sizeof f);
    int n; cin >> n;
    int _;
    while (n--) {
        cin >> _;
        a.emplace_back(_);
    }
    int m; cin >> m;
    while (m--) {
        cin >> _;
        b.emplace_back(_);
    }

    int s{};
    for (auto& _ : a)
        s ^= sg(_);

    if (s) {
        cout << "YES\n";
        for (int i{}; i < a.size(); ++i) {
            for (auto& _ : b) {
                if (a[i] < _) break;
                if ((s ^ sg(a[i]) ^ sg(a[i] - _)) == 0) {
                    cout << i + 1 << " " << _ << "\n";
                    return 0;
                }
            }
        }
    } else cout << "NO\n";


    return 0;
}