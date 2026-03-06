#include <bits/stdc++.h>
using namespace std;

string str;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> str;
    int t; cin >> t;
    int b, e; string l, r;
    // t = 1;
    while (t--) {
        cin >> b >> e >> l >> r;
        --b, e;
        string u{str.substr(b, e - b)};
        // cout << "u:" << u << "\n";
        str = str.replace(b, e - b, "");
        size_t pos{str.find(l + r)};
        // cout << pos << "\n";
        if (pos == string::npos) {
            str += u;
        } else {
            str = str.replace(pos + l.size(), 0, u);
        }
        // cout << str << "\n";
    }
    cout << str;
    return 0;
}