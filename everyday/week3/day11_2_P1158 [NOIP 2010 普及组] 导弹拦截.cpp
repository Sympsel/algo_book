#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int xa, ya, xb, yb;
int n;
struct node {
    int d1, d2;
    node(int _d1 = 0, int _d2 = 0) : d1(_d1), d2(_d2) {}

    bool operator<(const node& o) const {
        return d1 < o.d1;
    }
}a[N];

inline int dist(int x0, int y0, int x, int y) {
    return (x - x0) * (x - x0) + (y - y0) * (y - y0);
}

int main() {
    cin >> xa >> ya >> xb >> yb;
    cin >> n;
    int x, y;
    for (int i{1}; i <= n; ++i) {
        cin >> x >> y;
        a[i].d1 = dist(x, y, xa, ya);
        a[i].d2 = dist(x, y, xb, yb);
    }
    sort(a + 1, a + 1 + n);

    int min2{};
    int ret{a[n].d1};
    for (int i{n}; i >= 1; --i) {
        auto [d1, d2]{a[i]};
        min2 = max(min2, d2);
        if (i == 1) {
            ret = min(ret, min2);
        } else {
            ret = min(ret, a[i - 1].d1 + min2);
        }
    }
    cout << ret << "\n";
    return 0;
}
