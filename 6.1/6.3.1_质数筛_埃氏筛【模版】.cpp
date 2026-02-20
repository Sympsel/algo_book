#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 7;
using ll = long long;
bool st[N];
int p[N], cnt;
int n;

void sel() {
    for (int i{2}; i <= n; ++i) {
        if (st[i]) continue;
        p[++cnt] = i;

        for (ll j{1ll * i * i}; j <= n; j += i)
            st[j] = true;
    }
}

int main() {
    int q, x;
    scanf("%d%d", &n, &q);
    sel();
    while (q--) {
        scanf("%d", &x);
        printf("%d\n", p[x]);
    }

    return 0;
}