#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int a[N];
int b[N];

inline int sp(int h, int m) {
    return h * 60 + m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    int id, h, m;
    char t, _;
    while (T--) {
        memset(a, -1, sizeof a);
        memset(b, -1, sizeof b);
        int cnt{};
        int ret{};
        while (cin >> id >> t >> h >> _ >> m, id) {
            if (t == 'S') {
                a[id] = sp(h, m);
            } else {
                if (a[id] == -1) continue;
                b[id] = sp(h, m);
                ret += b[id] - a[id];
                a[id] = -1;
                ++cnt;
            }
        }
        cout << cnt << " " << (cnt == 0 ? ret : (int)((1.f * ret) / cnt + 0.5)) << "\n";
    }

    return 0;
}
