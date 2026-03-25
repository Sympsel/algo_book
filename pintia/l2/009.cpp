#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
struct node {
    int id, cnt, rec;
    node(int _id = 0, int _cnt = 0, int _rec = 0) : id(_id), cnt(_cnt), rec(_rec) {}
    bool operator<(const node& o) const {
        if (rec != o.rec) return rec > o.rec;
        if (cnt != o.cnt) return cnt > o.cnt;
        return id < o.id;
    }
};
node a[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int k, id, money;
    for (int i{1}; i <= n; ++i) {
        a[i].id = i;
    }
    for (int i{1}; i <= n; ++i) {
        cin >> k;
        while (k--) {
            cin >> id >> money;
            a[i].rec -= money;
            a[id].rec += money;
            ++a[id].cnt;
        }
    }
    sort(a + 1, a + 1 + n);
    for (int i{1}; i <= n; ++i) {
        auto& [id, _, rec]{a[i]};
        cout << id << " " << fixed << setprecision(2) << 1.0 * rec / 100 << "\n";
    }
    return 0;
}