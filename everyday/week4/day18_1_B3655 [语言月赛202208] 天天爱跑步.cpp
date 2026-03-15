#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
map<int, int> mp;
using ll = long long;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n; int _;
    cin >> _; mp[1] = _;
    cin >> _; mp[3] = _;
    cin >> _; mp[7] = _;
    cin >> _; mp[30] = _;
    cin >> _; mp[120] = _;
    cin >> _; mp[365] = _;
    int a[8]{0,1,3,7,30,120, 365, 0x3f3f3f3f};

    int cnt{};
    bool st;
    ll ret{};
    for (int i{1}; i <= n; ++i) {
        cin >> st;
        if (st) ++cnt;
        else {
            cnt = 0;
        }
        for (int i{}; i <= 6; ++i) {
            if (cnt >= a[i] && cnt < a[i + 1]) {
                ret += mp[a[i]];
            }
        }
    }
    cout << ret << "\n";
    return 0;
}
