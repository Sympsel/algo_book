#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
int n, a[N];
bool st[N];
int uf[N];

inline int fd(int x) {
    return x == uf[x] ? x : uf[x] = fd(uf[x]);
}

inline void un(int x, int y) {
    int fx{fd(x)}, fy{fd(y)};
    if (fx != fy) {
        uf[fx] = fy;
    }
}

// 总人数
unordered_set<int> total;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (int i{1}; i < N; ++i) uf[i] = i;
    while (t--) {
        int num; cin >> num;
        int fir, _;
        cin >> fir;
        st[fir] = true;
        total.emplace(fir);
        while (--num) {
            cin >> _;
            st[_] = true;
            total.emplace(_);
            un(fir, _);
        }
    }

    int all{};
    int con{};
    for (int i{1}; i < N; ++i) {
        if (!st[i]) continue;
        ++all;
        if (uf[i] == i) ++con;
    }
    cout << total.size() << " " << con << "\n";
    int T; cin >> T;
    while (T--) {
        int u, v; cin >> u >>v;
        if (fd(u) == fd(v))
            cout << "Y\n";
        else cout << "N\n";
    }

    return 0;
}
