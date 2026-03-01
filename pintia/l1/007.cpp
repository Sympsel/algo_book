#include <bits/stdc++.h>
using namespace std;

string mp[10] = {
    "ling", "yi", "er", "san", "si",
    "wu", "liu", "qi", "ba", "jiu"
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string num; cin >> num;
    if (num.size() && num[0] == '-')
        cout << "fu ";
    int sz(num.size());
    for (int i{}; i < sz; ++i) {
        char ch{num[i]};
        if (ch == '-') continue;
        if (i < sz - 1) {
            cout << mp[ch - '0'] << " ";
        } else {
            cout << mp[ch - '0'];
        }
    }

    return 0;
}