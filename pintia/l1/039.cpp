#include <bits/stdc++.h>
using namespace std;

const int N = 103;
stack<char> st[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string line;
    cin.ignore();
    getline(cin, line);
    int sz(line.size());
    int m{(sz + n - 1) / n * n};
    for (int i{}; i < m; ++i) {
        if (i < sz) {
            st[i % n].emplace(line[i]);
        } else {
            st[i % n].emplace(' ');
        }
    }

    for (int i{}; i < n; ++i) {
        while (st[i].size()) {
            cout << st[i].top();
            st[i].pop();
        }
        cout << "\n";
    }

    return 0;
}
