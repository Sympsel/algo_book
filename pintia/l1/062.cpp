#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    string str;
    while (t--) {
        int suma{}, sumb{};
        cin >> str;
        int i{};
        for (; i < 3; ++i) {
            suma += str[i];
        }
        for (; i < 6; ++i) {
            sumb += str[i];
        }
        if (suma == sumb) cout << "You are lucky!\n";
        else cout << "Wish you good luck.\n";
    }

    return 0;
}