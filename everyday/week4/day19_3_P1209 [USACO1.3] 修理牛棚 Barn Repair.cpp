#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int m, s, n;
int a[N];
bool st[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> s >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    for (int i{1}; i <= n; ++i) {
        st[a[i]] = true;
    }

    int len{a[n] - a[1] + 1};
    priority_queue<int> q;

    int cur{};
    for (int i{a[1]}; i <= a[n]; ++i) {
        if (st[i] == 0) {
            ++cur;
        } else {
            if (cur) q.emplace(cur);
            cur = 0;
        }
    }
    while (--m && q.size()) {
        len -= q.top();
        q.pop();
    }
    cout << len << "\n";

    return 0;
}