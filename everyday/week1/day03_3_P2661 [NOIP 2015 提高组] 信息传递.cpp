#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n;
int a[N];
int in[N];
int st[N];

int cnt;
void dfs(int x) {
    ++cnt;
    st[x] = true;
    int y{a[x]};
    if (!st[y]) dfs(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        ++in[a[i]];
    }

    queue<int> q;
    for (int i{1}; i <= n; ++i) {
        if (in[i] == 0) {
            q.emplace(i);
        }
    }
    while (q.size()) {
        auto t{q.front()}; q.pop();
        st[t] = true;
        int x{a[t]};
        --in[x];
        if (in[x] == 0) {
            q.emplace(x);
        }
    }

    int ret{0x3f3f3f3f};
    for (int i{1}; i <= n; ++i) {
        if (!st[i]) {
            cnt = 0;
            dfs(i);
            ret = min(ret, cnt);
        }
    }
    cout << ret << "\n";


    return 0;
}