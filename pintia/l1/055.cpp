#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y; cin >> x >> y;
    int a{}, b{};
    char t;
    int _{3};
    while (_--) {
        cin >> t;
        if (t == '0') ++a;
        else ++b;
    }

    if (a > 0 && x > y || a == 3 && x < y) {
        cout << "The winner is a: " << x << " + " << a;
    } else {
        cout << "The winner is b: " << y << " + " << b;
    }

    return 0;
}
