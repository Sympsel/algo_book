#include <bits/stdc++.h>
using namespace std;

const int MAX = 11;
vector<pair<string, string>> m;
unordered_set<string> hs;
string src, dest;
int ret{MAX};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> src >> dest;
    string u, v;
    while (cin >> u >> v)
        m.emplace_back(u, v);

    int ret{};
    queue<string> q;
    unordered_set<string> used;

    q.emplace(src);
    while (q.size()) {
        int t(q.size());
        if (ret > 10) {
            cout << "NO ANSWER!\n";
            return 0;
        }
        while (t--) {
            auto cur{q.front()}; q.pop();
            if (cur == dest) {
                cout << ret << "\n";
                return 0;
            }
            used.emplace(cur);

            for (auto [u, v] : m) {
                size_t pos{};
                while ((pos = cur.find(u, pos)) != string::npos) {
                    string next{cur};
                    next.replace(pos, u.size(), v);
                    if (!used.count(next)) {
                        q.emplace(next);
                        used.emplace(next);
                    }
                    ++pos;
                }
            }
        }
        ++ret;
    }
    cout << "NO ANSWER!\n";
    return 0;
}
