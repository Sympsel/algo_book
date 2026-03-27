#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, m;
using ll = long long;
vector<int> ed[N];
double w[N];
double ks[N];
double w0, r, k;
unordered_set<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w0 >> r;
    for (int i{}; i < n; ++i) ks[i] = 1.0;
    w[0] = w0;
    int sz;
    for (int i{}; i < n; ++i) {
        cin >> sz;
        if (sz == 0) {
            cin >> k;
            ks[i] = k;
            st.emplace(i);
        } else {
            int id;
            while (sz--) {
                cin >> id;
                ed[i].emplace_back(id);
            }
        }
    }

    queue<int> q;
    q.emplace(0);
    while (q.size()) {
        auto& u{q.front()};
        for (auto& v : ed[u]) {
            w[v] = w[u] * (100.0 - r) / 100;
            q.emplace(v);
        }
        q.pop();
    }
    double sum{};
    for (int i{}; i < n; ++i) {
        if (st.count(i)) {
            sum += w[i] * ks[i];
        }
    }
    cout << (ll)sum << "\n";

    return 0;
}
