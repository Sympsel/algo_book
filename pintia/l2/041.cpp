#include <bits/stdc++.h>
#include <iterator>
using namespace std;

int n, m, k;
queue<int> q;
vector<vector<int>> ret;
stack<int> st;

int main() {
    cin >> n >> m >> k;
    for (int i{}; i < n; ++i) {
        int x; cin >> x;
        q.emplace(x);
    }

    vector<int> line;
    while (q.size() || st.size()) {
        bool flag{};
        if (st.size() && (line.empty() || line.back() >= st.top())) {
            line.emplace_back(st.top());
            st.pop();
            flag = true;
        }

        if (!flag && q.size() && (line.empty() || line.back() >= q.front())) {
            line.emplace_back(q.front());
            q.pop();
            flag = true;
        }
        if (!flag) {
            if (line.size()) ret.emplace_back(line);
            line.clear();
        }

        {
            if (line.empty() || line.back() >= q.front()) {
                line.emplace_back(q.front());
                q.pop();
            } else {
                st.emplace(q.front());
                q.pop();
            }
        }
    }

    return 0;
}
