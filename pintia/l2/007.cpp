#include <bits/stdc++.h>
using namespace std;

const int N = 10003;
int n = 9999;

unordered_map<int, pair<int, int>> peo;
int uf[N];
bool st[N]; // 标记该人是否存在
int fd(int x) {
    return x == uf[x] ? x : uf[x] = fd(uf[x]);
}

void un(int x, int y) {
    // 让家庭中编号最小的作为根
    // if (x < y) swap(x, y);
    int fx{fd(x)}, fy{fd(y)};
    if (fx < fy) swap(fx, fy);
    uf[fx] = fy;

}

void init() {
    for (int i{1}; i <= n; ++i) uf[i] = i;
    int t; cin >> t;
    int id, pa, pb, k, child, cnt, area;
    while (t--) {
        cin >> id >> pa >> pb >> k;
        st[id] = true;
        if (pa != -1) {
            st[pa] = true;
            un(pa, id);
        }
        if (pb != -1) {
            st[pb] = true;
            un(pb, id);
        }
        for (int i{1}; i <= k; ++i) {
            cin >> child;
            st[child] = true;
            un(child, id);
        }
        cin >> cnt >> area;
        peo[id] = {cnt, area};
    }
}

inline bool equal(const double& x, const double& y) {
    return x - y < 1e-9;
}

struct Info_t {
    int _id, _mem_sz, _cnt, _area;
    Info_t(int id = 0, int mem_sz = 0, int cnt = 0, int area = 0)
    : _id(id), _mem_sz(mem_sz), _cnt(cnt), _area(area) {}

    bool operator<(const Info_t& o) const {
        double avg_area1 = 1.0 * _area / _mem_sz;
        double avg_area2 = 1.0 * o._area / o._mem_sz;
        // 比较取反，因为要放入大根堆中
        if (equal(avg_area1, avg_area2)) return _id > o._id;
        return avg_area1 < avg_area2;
    }
};

unordered_map<int, int> family;
unordered_map<int, pair<int, int>> info;
priority_queue<Info_t> ret;
void solve() {
    for (int i{1}; i <= n; ++i) {
        if (!st[i]) continue;
        int root{fd(i)};
        ++family[root];
        if (peo.count(i)) {
            info[root].first += peo[i].first;
            info[root].second += peo[i].second;
        }
    }
    cout << family.size() << "\n";
    for (auto [id, tmp] : info) {
        auto [cnt, area]{tmp};
        ret.emplace(id, family[id], cnt, area);
    }

    while (ret.size()) {
        auto [id, mem_sz, cnt, area]{ret.top()}; ret.pop();
        cout << setfill('0') << setw(4) << to_string(id) << " " << mem_sz << " "
        << fixed << setprecision(3)
        << 1.0 * cnt / mem_sz << " "
        << 1.0 * area / mem_sz << "\n";
    }
}

int main() {
    init();
    solve();
    return 0;
}
