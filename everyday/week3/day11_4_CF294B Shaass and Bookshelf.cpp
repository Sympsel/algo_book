#include <bits/stdc++.h>
using namespace std;

const int N = 103;
const int M = 1e5 + 7;

int f[M];
int t[N], w[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int sum{};
    for (int i{1}; i <= n; ++i) {
        cin >> t[i] >> w[i];
        sum += t[i];
    }
    memset(f, 0x3f, sizeof f);
    f[0] = 0;

    for (int i{1}; i <= n; ++i) {
        for (int j{sum}; j >= t[i]; --j) {
            f[j] = min(f[j], f[j - t[i]] + w[i]);
        }
    }
    for (int i{sum}; i >= 0; --i) {
        if (f[i] <= sum - i) {
            cout << sum - i << "\n";
            return 0;
        }
    }

    return 0;
}