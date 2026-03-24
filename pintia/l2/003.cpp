#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

const int N = 1e3 + 7;
int n, m;
using ll = long long;
struct node {
    ll cnt, total;
    node(double _cnt = 0, double _total = 0) : cnt(_cnt), total(_total) {}
    bool operator<(const node& o) const {
        return total * o.cnt < o.total * cnt;
    }
};
ll b[N], c[N];

int main() {
    cin >> n >> m;
    for (int i{1}; i <= n; ++i) cin >> b[i];
    for (int i{1}; i <= n; ++i) cin >> c[i];
    priority_queue<node> q;
    for (int i{1}; i <= n; ++i) {
        q.emplace(b[i], c[i]);
    }
    ll cur{};
    double ret{};
    while (!q.empty() && cur < m) {
        auto [cnt, total]{q.top()}; q.pop();
        if (cur + cnt <= m) {
            ret += total;
            cur += cnt;
        } else {
            ret += 1.0 * total / cnt * (m - cur);
            break;
        }
    }
    cout << fixed << setprecision(2) << ret << "\n";
    return 0;
}
