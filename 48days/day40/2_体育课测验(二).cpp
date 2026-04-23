#include <bits/stdc++.h>
using namespace std;


const int N = 2e3 + 7;
class Solution {
private:
    int in[N];
    vector<int> ed[N];

public:
    vector<int> findOrder(int n, vector<vector<int> >& a) {
        for (auto& pairs : a) {
            int v = pairs[0], u = pairs[1];
            ++in[v];
            ed[u].emplace_back(v);
        }
        queue<int> q;
        vector<int> ret;
        for (int i{}; i < n; ++i) {
            if (in[i] == 0) {
                q.emplace(i);
                ret.emplace_back(i);
            }
        }
        int cnt{};
        while (q.size()) {
            int sz(q.size());
            cnt += sz;
            bool has{};
            while (sz--) {
                auto u{q.front()}; q.pop();
                for (auto v : ed[u]) {
                    --in[v];
                    if (in[v] == 0) {
                        ret.emplace_back(v);
                        q.emplace(v);
                        has = true;
                    }
                }
            }
            if (has == false && cnt < n) {
                return {};
            }
        }
        return ret;
    }
};
