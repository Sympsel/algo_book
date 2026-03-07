#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    string res{str};
    str.erase(str.find('-'), 1);
    str.erase(str.find('-'), 1);
    str.erase(str.find('-'), 1);

    int ret{};
    for (int i{}; i < 9; ++i) {
        ret += (i + 1) * (str[i] - '0') % 11;
    }
    ret %= 11;

    char x;
    if (ret == 10) x = 'X';
    else x = ret + '0';

    if (str.back() == x)
        cout << "Right\n";
    else {
        res.back() = x;
        cout << res;
    }


    return 0;
}