#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7 + 3;
int n;
int pri[N];
int phi[N], cnt;
bool st[N];

void get_phi() {
    phi[1] = 1;
    for (int i{2}; i <= n; ++i) {
        if (!st[i]) {
            pri[++cnt] = i;
            phi[i] = i - 1;
        }

        for (int j{1}; 1ll * i * pri[j] <= n; ++j) {
            int x{i * pri[j]};
            st[x] = true;
            if (i % pri[j] == 0) {
                phi[x] = pri[j] * phi[i];
                break;
            }
            phi[x] = (pri[j] - 1) * phi[i];
        }
    }
}

ll qpow(ll b, ll p) {
    ll ret{1};
    ll a{2};
    while (b) {
        if (b & 1) ret = ret * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ret;
}

ll dfs(ll p) {
    if (p == 1) return 0;
    return qpow(dfs(phi[p]) + phi[p], p);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n = 1e7;
    get_phi();

    int t; cin >> t;
    ll p;
    while (t--) {
        cin >> p;
        cout << dfs(p) << "\n";
    }

    return 0;
}