#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 7;
int n, q;
int pos;
int p[N];
bool st[N];
using ll = long long;

int main() {
    scanf("%d%d", &n, &q);
    for (ll i{2}; i <= n; ++i) {
        if (!st[i]) {
            p[++pos] = i;
        }

        int x{};
        for (ll j{1}; i * p[j] <= n; ++j) {
            st[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
    int x;
    while (q--) {
        scanf("%d", &x);
        printf("%d\n", p[x]);
    }

    return 0;
}