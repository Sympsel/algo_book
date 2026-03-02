#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int n, m, k;
int a[N][N];
bool row[N], col[N];
using node = tuple<int, int, int>;

struct cmp {
    bool operator()(const node& x, const node& y) {
        auto [u, _1, _2]{x};
        auto [v, _3, _4]{y};
        return u < v;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    priority_queue<node, vector<node>, cmp> q;
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            cin >> a[i][j];
            q.emplace(a[i][j], i, j);
        }
    }

    while (q.size() && k) {
        auto [_, r, c]{q.top()}; q.pop();
        if (row[r] || col[c]) continue;
        row[r] = true;
        col[c] = true;
        k--;
    }

    for (int i{}; i < n; ++i) {
        bool rhas{};
        for (int j{}; j < m; ++j) {
            if (!row[i] && !col[j]) {
                if (rhas) cout << " ";
                cout << a[i][j];
                rhas = true;
            }
        }
        if (rhas && i != n - 1) cout << "\n";
    }

    return 0;
}