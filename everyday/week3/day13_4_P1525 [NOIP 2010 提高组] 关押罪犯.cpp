#include <bits/stdc++.h>
using namespace std;

const int N = 4e4 + 7;
const int M = 1e5 + 7;
int n, m;
int uf[N];

int fd(int x) {
    return x == uf[x] ? x : uf[x] = fd(uf[x]);
}

void un(int x, int y) {
    uf[fd(x)] = fd(y);
}

struct node {
    int w, x, y;
    node(int _w = 0, int _x = 0, int _y = 0) : w(_w), x(_x), y(_y) {}
    bool operator<(const node& o) const {
        return w > o.w;
    }
}a[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i{1}; i <= 2 * n; ++i) uf[i] =i;
    int x, y, w;
    for (int i{1}; i <= m; ++i) {
        cin >> x >> y >>w;
        a[i] = {w,x,y};
    }
    sort(a +1, a+ n + 1);
    for (int i{1}; i <= m; ++i) {
        auto [w, x, y]{a[i]};
        un(x, y + n);
        un(y, x + n);
        if (fd(x) == fd(y)) {
            cout << w << "\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}