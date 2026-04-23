#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

const int N = 1e5 + 7;
int a[N];
int b[N];

int main() {
    int n; cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    for (int i{1}; i <= n; ++i) {
        q.emplace(a[i]);
        if (q.size() > 2) {
            q.pop();
        }
        b[i] = q.top();
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << x << "\n";
    }
    return 0;
}