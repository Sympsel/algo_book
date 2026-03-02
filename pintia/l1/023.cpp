#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int a{}, b{}, c{}, d{};
    for (auto& ch : s) {
        if (ch >= 'a' && ch <= 'z') ch -= 32;
        if (ch == 'G') ++a;
        else if (ch == 'P') ++b;
        else if (ch == 'L') ++c;
        else if (ch == 'T') ++d;
        else {}
    }

    while (a || b || c || d) {
        if (a) {
            putchar('G');
            --a;
        }
        if (b) {
            putchar('P');
            --b;
        }
        if (c) {
            putchar('L');
            --c;
        }
        if (d) {
            putchar('T');
            --d;
        }
    }

    return 0;
}
