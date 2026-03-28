#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

struct Peo {
    string _name, _id;
    bool _status;
    int _time;
    int _idx;
    Peo(string name = "", string id = "", bool status = false, int time = 0, int idx = 0) :
    _name(name), _id(id), _status(status), _time(time), _idx(idx) {}

    bool operator<(const Peo& o) const {
        if (_time == o._time) return _idx < o._idx;
        return _time < o._time;
    }
};

unordered_map<string, int> last; // 记录上次领取时间
int n, p;
vector<Peo> a; // 记录有效数据

vector<pair<string, string>> ret; // 记录身体状况为1的人
unordered_set<string> st; // 对身体状况为1去重

int cur{};

void solve(int n, const int k, const int day) {
    a.clear();
    // 筛选合法数据
    while (n--) {
        string name, id;
        bool status;
        int h, m; char _;
        cin >> name >> id >> status >> h >> _ >> m;
        if (id.size() != 18) continue;
        for (int i{}; i < (int)id.size(); ++i)
            if (id[i] < '0' || id[i] > '9') goto next;

        a.emplace_back(name, id, status, h * 60 + m, ++cur);
        next:;
    }
    sort(a.begin(), a.end());
    int cnt{};
    for (int i{}; i < (int)a.size(); ++i) {
        auto [name, id, status, time, _]{a[i]};
        if (status && !st.count(id)) {
            ret.emplace_back(name, id);
            st.emplace(id);
        }
        // 筛掉短期多次领取
        if (last.count(id) && last[id] + p >= day) continue;
        last[id] = day;
        ++cnt;
        cout << name << " " << id << "\n";
        // 当领取人数大于k时退出
        if (cnt >= k) break;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p;
    for (int i{1}; i <= n; ++i) {
        int t, k;
        cin >> t >> k;
        solve(t, k, i);
        // cout << "\n"; // 调试用换行
    }

    for (auto& [name, id] : ret) {
        cout << name << " " << id << "\n";
    }

    return 0;
}
