#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;
using ll =long long;
int n;
ll a[N];
struct node {
    int l, r;
    ll sum;
}tr[N << 2];

#define lc (p << 1)
#define rc (p << 1 | 1)

inline void pushup(int p) {
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void build(int p, int l, int r) {
    tr[p] = {l, r, a[l]};
    if (l == r) return;
    int mid{(l + r) >> 1};

    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}

ll query(int p, int ql, int qr) {
    int l{tr[p].l}, r{tr[p].r};
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return tr[p].sum;
    ll ls{query(lc, ql, qr)};
    ll rs{query(rc, ql, qr)};
    return ls + rs;  
}

void modify(int p, int x, ll val) {
    int l{tr[p].l}, r{tr[p].r};
    if (x == l && x == r) {
        tr[p].sum += val;
        return;
    }
    int mid{(l + r) >> 1};
    if (x <= mid) modify(lc, x, val);
    else modify(rc, x, val);
    pushup(p);
}

int main() {
    cin >> n;
    int q; cin >> q;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int op, x, y; cin >> op >> x >> y;
        if (op == 1) {
            modify(1, x, y);
        } else if (op == 2) {
            cout << query(1, x, y) << endl;
       } else {}
    }
    return 0;
}
