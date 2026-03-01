#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; char ch;
    cin >> n >> ch;
    int w = (int)(1.0 * n / 2 + 0.5);
    string str;
    while (n--) {
        str += ch;
    }

    while (w--) {
        if (w == 0) cout << str;
        else cout << str << "\n";
    }

    return 0;
}
