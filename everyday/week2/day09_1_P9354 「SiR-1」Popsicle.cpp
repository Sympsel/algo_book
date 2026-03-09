#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    string str;
    while (t--) {
        cin >> str;
        ll ret{};
        bool zero{};
        for (auto& ch : str) {
            ret += ch - '0';
            if (ch == '0') zero = true;
        }
        ret += zero ? 9 : 8;
        cout << ret << "\n";
    }

    return 0;
}