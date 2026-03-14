#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    while (b) {
        int new_b{a % b};
        a = b;
        b = new_b;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int b;
    cin >> s >> b;
    long long a{};
    for (int i{}; i < s.size(); ++i) {
        a = (a * 10 + s[i] - '0') % b;
    }
    cout << gcd((int)a, b) << "\n";

    return 0;
}