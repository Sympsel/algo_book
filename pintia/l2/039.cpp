#include <bits/stdc++.h>
#include <sstream>
#include <vector>
using namespace std;

int n, m;
const int N = 1e4 + 7;
unordered_map<string, int> mp;

struct node {
    int _cnt;
    string _output;
    vector<int> _nums;

    bool operator<(const node& o) const {
        if (_cnt != o._cnt)
            return _cnt > o._cnt;
        return _nums < o._nums;
    }
};

int main() {
    cin >> n >> m;
    cin.ignore();
    for (int i{}; i < n; ++i) {
        string line; getline(cin, line);
        ++mp[line];
    }
    vector<node> ret;
    for (auto& [output, cnt] : mp) {
        node cur;
        cur._cnt = cnt;
        cur._output = output;
        istringstream iss(output);
        vector<int> v;
        int x;
        while (iss >> x) {
            v.emplace_back(x);
        }
        cur._nums = v;
        ret.emplace_back(cur);
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for (auto cur : ret) {
        cout << cur._cnt << " " << cur._output << "\n";
    }
    return 0;
}
