#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; char ch;
    cin >> n >> ch;
    string src;
    getline(cin, src);
    getline(cin, src);
    int n0 = src.size();
    if (n0 > n) {
        src = src.substr(n0 - n, n0);
    } else if (n0 < n) {
        string t;
        int _{n - n0};
        while (_--) t += ch;
        src = t + src;
    } else {}
    cout << src;

    return 0;
}
