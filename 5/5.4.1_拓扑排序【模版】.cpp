#include <bits/stdc++.h>
using namespace std;

const int N = 103;
vector<int> g[N];
int in[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n; int x;
    for (int i{1}; i <= n; ++i)
        while (cin >> x, x) {
            g[i].emplace_back(x);
            ++in[x];
        }

    queue<int> q;
    for (int i{1}; i <= n; ++i)
        if (!in[i])
            q.emplace(i);

    while (q.size()) {
        auto t{q.front()}; q.pop();
        cout << t << " ";

        for (auto _ : g[t]) {
            --in[_];
            if (!in[_])
                q.emplace(_);
        }
    }

    return 0;
}
