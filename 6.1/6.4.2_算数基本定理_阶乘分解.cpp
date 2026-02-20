#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using ll = long long;
int n;
int p[N], cnt;
bool st[N];

void sel() {
    for (int i{2}; i <= n; ++i) {
        if (!st[i]) p[++cnt] = i;
        for (int j{1}; 1ll * i * p[j] <= n; ++j) {
            st[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    sel();

    for (int i{1}; i <= cnt; ++i) {
        int c{};
        for (ll j{1ll * p[i]}; j <= n; j *= p[i]) {
            c += n / j;
        }
        cout << p[i] << " " << c << "\n";
    }

    return 0;
}