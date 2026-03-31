#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
// int d[N];
vector<int> d[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n / i; ++j) {
            d[i * j].emplace_back(i);
        }
    }

    for (int i{1}; i <= n; ++i) {
        cout << i << ": ";
        for (const auto& x : d[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }


    return 0;
}