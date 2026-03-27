#include <bits/stdc++.h>
using namespace std;

// const int N =
int n, m;
unordered_set<string> tab;
// unordered_map<string, int> mp;
priority_queue<pair<int, string>> q;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    string name;
    for (int i{}; i < n; ++i) {
        cin >> name;
        tab.emplace(name);
    }
    cin >> m;
    int cnt;
    ll sum{};
    for (int i{}; i < m; ++i) {
        cin >> name >> cnt;
        // mp[name] = cnt;
        q.emplace(cnt, name);
        sum += cnt;
    }
    double avg{1.0 * sum / m};
    priority_queue<string, vector<string>, greater<string>> ret;
    while (q.size()) {
        auto [cnt, name]{q.top()}; q.pop();
        if (cnt > avg && !tab.count(name)) {
            ret.emplace(name);
        }
    }
    if (ret.size() == 0) {
        cout << "Bing Mei You";
        return 0;
    }
    while (ret.size()) {
        cout << ret.top() << "\n";
        ret.pop();
    }

    return 0;
}