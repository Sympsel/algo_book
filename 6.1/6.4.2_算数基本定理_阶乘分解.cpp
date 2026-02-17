#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n;
int cnt[N];
bool st[N];
vector<int> p;
using ll = long long;


void getp() {
    for (int i{2}; i <= n; ++i) {
        if (!st[i]) p.emplace_back(i);

        for (auto& x : p) {
            if (1ll * i * x > n) break;
            st[i * x] = true;
            if (i % x == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    getp();

    for (int i{2}; i <= n; ++i) {
        if (st[i]) continue;
        ll t{i};
        while (1LL * n >= t) {
            cnt[i] += n / t;
            t *= i;
        }
    }

    for (int i{2}; i <= n; ++i)
        if (cnt[i])
            cout << i << " " << cnt[i] << "\n";

    return 0;
}