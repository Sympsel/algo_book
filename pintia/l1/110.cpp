#include <bits/stdc++.h>
using namespace std;

int n;

string cintostr(int n) {
    string ret;
    int x;
    for (int i{}; i < n; ++i) {
        cin >> x;
        ret += (char)(x + 97);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> n >> t;
    int x;
    string str{cintostr(n)};
    // cout << str;
    int op;
    while (t--) {
        cin >> op;
        if (op == 1) {
            int sz1, sz2; cin >> sz1;
            string u{cintostr(sz1)};
            cin >> sz2;
            string v{cintostr(sz2)};
            size_t pos{str.find(u)};
            if (pos == string::npos) continue;
            str.replace(pos, sz1, v);
        } else if (op == 2) {
            string even;
            for (int i{}; i < (int)str.size() - 1; ++i) {
                if ((str[i] + str[i + 1]) % 2 == 0) {
                    even += (char)((str[i] + str[i + 1]) / 2);
                } else {
                    even += ' ';
                }
            }
            string tmp;
            for (int i{}; i < (int)even.size(); ++i) {
                tmp += str[i];
                if (even[i] != ' ') tmp += even[i];
            }
            tmp += str.back();
            str = tmp;
        } else if (op == 3) {
            int l, r; cin >> l >> r;
            --l, --r;
            while (l < r) {
                swap(str[l], str[r]);
                ++l; --r;
            }
        } else {}
    }

    for (int i{}; i < str.size(); ++i) {
        if (i > 0) cout << " ";
        cout << (str[i] - 97);
    }

    return 0;
}