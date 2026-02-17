#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n;
vector<int> p;
bool st[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    for (int i{2}; i <= n; ++i) {
        if (!st[i]) {
            p.emplace_back(i);
        }

        for (const auto& x : p) {
            st[i * x] = true;
            if (i % x == 0) break;
        }
    }

    for (const auto& x : p) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}