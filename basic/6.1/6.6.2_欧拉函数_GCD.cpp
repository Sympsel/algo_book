#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 7;
int n;
int p[N], cnt;
int phi[N];
long long f[N];
bool st[N];

void sel() {
    phi[1] = 1;
    for (int i{2}; i <= n; ++i) {
        if (!st[i]) {
            p[++cnt] = i;
            phi[i] = i - 1;
        }

        for (int j{1}; 1ll * i * p[j] <= n; ++j) {
            int x{i * p[j]};
            st[x] = true;
            if (i % p[j] == 0) {
                phi[x] = p[j] * phi[i];
                break;
            }
            phi[x] = (p[j] - 1) * phi[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    sel();

    for (int i{1}; i <= n; ++i) {
        f[i] = f[i - 1] + phi[i];
    }

    long long ret{};
    for (int i{1}; i <= cnt; ++i) {
        ret += 2ll * f[n / p[i]] - 1;
    }

    cout << ret << "\n";

    return 0;
}