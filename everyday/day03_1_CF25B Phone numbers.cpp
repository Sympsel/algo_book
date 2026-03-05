#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sz; cin >> sz;
    string s; cin >> s;
    for (int i{}; i < sz; ++i) {
        if (i > 0 && i % 2 == 0) {
            if (!(sz % 2 == 1 && i > sz - 2))
                cout << '-';
        }
        cout << s[i];
    }

    return 0;
}
