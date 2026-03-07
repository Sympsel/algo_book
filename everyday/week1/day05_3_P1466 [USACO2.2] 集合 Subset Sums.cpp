#include <bits/stdc++.h>
using namespace std;

const int N = 43;
int n;
const int M = 397;
using ll = long long;
ll f[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int sum{(n + 1) * n / 2};
    if (sum % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }
    int m{sum / 2};
    f[0] = 1;

    for (int i{1}; i <= n; ++i) {
        for (int j{m}; j >= i; --j) {
            f[j] += f[j - i];
        }
    }
    cout << f[m] / 2 << "\n";
    return 0;
}
