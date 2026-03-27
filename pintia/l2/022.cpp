#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n;
int dt[N], ne[N];
int addr[N], len;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int head;
    cin >> head >> n;

    for (int i{}; i < n; ++i) {
        int cur, val, nex;
        cin >> cur >> val >> nex;
        dt[cur] = val;
        ne[cur] = nex;
    }
    int cur{head};
    while (cur != -1) {
        addr[len++] = cur;
        cur = ne[cur];
    }

    vector<int> ret;
    int l{}, r{len - 1};
    while (l <= r) {
        if (l == r) {
            ret.emplace_back(addr[l]);
            break;
        }
        ret.emplace_back(addr[r]);
        ret.emplace_back(addr[l]);
        ++l, --r;
    }

    for (int i{}; i < ret.size(); ++i) {
        cout << setfill('0') << setw(5) << ret[i] << " " << dt[ret[i]];
        if (i + 1 == ret.size()) {
            cout << " -1\n";
        } else {
            cout << " " << setfill('0') << setw(5) << ret[i + 1] << "\n";
        }
    }
    return 0;
}
