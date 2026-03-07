#include <bits/stdc++.h>
using namespace std;

int k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str; cin >> str;
    cin >> k;
    while (k--) {
        bool flag{};
        for (int i{}; i < (int)str.size() - 1; ++i) {
            if (str[i] > str[i + 1]) {
                str.erase(i, 1);
                flag = true;
                break;
            }
        }
        if (!flag) str.pop_back();
    }
    int i{};
    while (str[i] == '0' && i < str.size() && str.size() > 1) ++i;
    cout << str.substr(i, str.size());
    return 0;
}