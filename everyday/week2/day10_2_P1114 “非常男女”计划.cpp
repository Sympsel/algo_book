#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n;
int s[N];
unordered_map<int, int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mp[0] = 0;
    cin >> n;
    char _;
    int ret{};
    for (int i{1}; i <= n; ++i) {
        cin >> _;
        if (_ == '0') s[i] = -1;
        else s[i] = 1;
        s[i] += s[i - 1];
        if (mp.count(s[i])) {
            ret = max(ret, i - mp[s[i]]);
        } else {
            mp.emplace(s[i], i);
        }
    }
    cout << ret << "\n";
    
    return 0;
}
