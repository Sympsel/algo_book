#include <bits/stdc++.h>
using namespace std;

struct node {
    int _cnt;
    double _avg;
    string _name;

    node(int cnt = 0, double avg = 0.0, string name = "") : _cnt(cnt), _avg(avg), _name(name) {}
    bool operator<(const node& o) const {
        if (_cnt == o._cnt) return _avg > o._avg;
        return _cnt < o._cnt;
    }
};

priority_queue<node> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    if (n == 0) {
        cout << "- - -";
        return 0;
    }
    string name; int tag;
    int m;
    for (int i{}; i < n; ++i) {
        unordered_set<int> st;
        cin >> name >> m;
        for (int j{}; j < m; ++j) {
            cin >> tag;
            st.emplace(tag);
        }
        int sz((int)st.size());
        q.emplace(sz, 1.0 * m / sz, name);
    }
    bool is_first{true};
    int i{};
    while (i < 3 && q.size()) {
        if (is_first) is_first = false;
        else cout << " ";
        cout << q.top()._name;
        q.pop();
        ++i;
    }
    if (i < 3) {
        cout << " -";
        ++i;
    }
    return 0;
}
