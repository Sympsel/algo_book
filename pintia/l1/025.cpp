#include <bits/stdc++.h>
using namespace std;

bool valid(string x) {
    if (x.size() == 0) return false;
    for (auto& ch : x) {
        if (ch < '0' || ch > '9') return false;
    }
    int X{stoi(x)};
    if (X < 1 || X > 1000) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x, y;
    char _;
    cin >> x;
    getline(cin, y);
    y = y.substr(1, y.size());
    // cout << "x:" << x << "\n" << "y:" << y << "\n";
    bool stx{valid(x)}, sty{valid(y)};
    if (stx && sty) {
        cout << stoi(x) << " + " << stoi(y) << " = " << (stoi(x) + stoi(y));
    } else if (!stx && !sty) {
        cout << "? + ? = ?";
    } else if (stx) {
        cout << stoi(x) << " + ? = ?";
    } else {
        cout << "? + " << stoi(y) << " = ?";
    }

    return 0;
}
