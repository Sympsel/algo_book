#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct Cmp {
    bool operator()(const pair<int, int> & a, const pair<int, int> & b) {
        return a.first * a.second > b.first * b.second;
    }
};

int main() {
    int n;
    while (cin >> n) {
        int val{};
        map<int, int> m;
        for (int i{}; i < n; ++i) {
            cin >> val;
            ++m[val];
        }

        int ret{};
        while (m.size() > 1) {
            int x{-0x7fffffff};
            int idx{};
            for (auto& [k, v] : m) {
                int a{m.count(k - 1) ? m[k - 1] * (k - 1) : 0};
                int b{m.count(k + 1) ? m[k + 1] * (k + 1) : 0};
                int y{k - ((m.count(k - 1) ? m[k - 1] * (k - 1) : 0) + (m.count(k + 1) ? m[k + 1] * (k + 1) : 0))};
                if (y > x) {
                    idx = k;
                    x = y;
                }
            }
            ret += idx;
            if (m[idx]) {
                --m[idx];
                if (!m[idx]) {
                    m.erase(idx);
                }
            }
            if (m[idx - 1]) {
                --m[idx - 1];
            }
            if (!m[idx - 1]) {
                m.erase(idx - 1);
            }
            if (m[idx + 1]) {
                --m[idx + 1];
            }
            if (!m[idx + 1]) {
                m.erase(idx + 1);
            }
        }
        if (m.size() == 1) {
            ret += m.begin()->first * m.begin()->second;
        }
        cout << ret << "\n";
    }
}
// 64 位输出请用 printf("%lld")