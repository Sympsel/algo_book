#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x{};
    int i{};
    while (cin >> x) {
        ++i;
        if (x == 250) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
