#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
struct Stu {
    string _name;
    int _score;
    bool operator<(const Stu& o) const {
        if (_score == o._score) return _name < o._name;
        return _score > o._score;
    }
}a[N];

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i]._name >> a[i]._score;
    }
    sort(a + 1, a + n + 1);
    int ret{};
    for (int i{1}; i <= n; ++i) {
        auto& [name, score]{a[i]};
        if (score < 60) break;
        if (score < m) {
            ret += 20;
        } else {
            ret += 50;
        }
    }
    cout << ret << "\n";

    int pre{-1}, cur_id{}, cnt{};
    for (int i{1}; i <= n; ++i) {
        auto& [name, score]{a[i]};
        if (score < 60) break;
        if (pre != score) {
            cnt = i; // 当发现不同时，重置cnt为数组下标
            cur_id = i;
            pre = score;
            if (cnt > k) break;
        }
        cout << cur_id << " " << name << " " << score << "\n";
    }

    return 0;
}
