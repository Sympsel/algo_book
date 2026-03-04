#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x;
    int k{}, q{1};
    while (q * 26 < x) {
        q *= 26;
        ++k;
    }

    string str;
    for (int i{}; i < n; ++i) str += 'z';
    cout << str << "\n";

    return 0;
}