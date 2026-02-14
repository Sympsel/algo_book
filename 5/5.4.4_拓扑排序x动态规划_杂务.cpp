#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
int n;
int in[N];
int out[N];
int w[N], f[N];
vector<int> g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int _, x;
    for (int i{1}; i <= n; ++i) {
        cin >> _ >> w[i];
        while (cin >> x, x) {
            g[x].emplace_back(i);
            ++in[i]; ++out[x];
        }
    }

    queue<int> q;
    for (int i{1}; i <= n; ++i)
        if (in[i] == 0)
            q.emplace(i);


    int time{};
    while (q.size()) {
        auto x{q.front()}; q.pop();
        f[x] += w[x];
        time = max(time, f[x]);


        for (auto y : g[x]) {
            f[y] = max(f[x], f[y]);
            --in[y];
            if (in[y] == 0)
                q.emplace(y);
        }
    }
    cout << time << '\n';

    return 0;
}
