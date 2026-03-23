#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int M = 1e6 + 7;
int n;
int cnt[M], ret[M];
int a[N];
int m = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    for (int i{1}; i <= m; ++i) {
        if (cnt[i] == 0) continue;
        for (int j{i}; j <= m; j += i) {
            ret[j] += cnt[i];
        }
    }
    for (int i{1}; i <= n; ++i) {
        cout << ret[a[i]] - 1 << "\n";
    }
    return 0;
}
