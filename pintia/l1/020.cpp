#include <bits/stdc++.h>
using namespace std;

const int N = 103;
unordered_set<int> a[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int m, _;
    for (int i{1}; i <= n; ++i) {
        cin >> m;
        while (m--) {
            cin >> _;
            a[i].emplace(_);
        }
    }

    unordered_set<int> used;
    cin >> m;
    stringstream ss;
    bool flag{};
    while (m--) {
        cin >> _;
        if (used.count(_)) continue;
        bool ok{};
        for (int i{1}; i <= n; ++i) {
            if (a[i].count(_) && a[i].size() != 1) {
                ok = true;
                break;
            }
        }
        used.emplace(_);
        if (ok) continue;
        if (!flag) flag = true;
        ss << setfill('0') << setw(5) << _ << " ";
    }
    if (!flag) {
        cout << "No one is handsome";
    } else {
        string ret{ss.str()};
        if (ret.back() == ' ') ret.pop_back();
        cout << ret;
    }

    return 0;
}
