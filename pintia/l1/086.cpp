#include <bits/stdc++.h>
using namespace std;

string algo(const string& s) {
    string ret;
    for (int i{1}; i < s.size(); ++i) {
        if (s[i] % 2 == s[i - 1] % 2) {
            ret += max(s[i], s[i - 1]);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    string ra{algo(s1)};
    string rb{algo(s2)};
    if (ra == rb) cout << ra;
    else cout << ra << "\n" << rb;


    return 0;
}