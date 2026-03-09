#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
using ll  = long long;
int a[N], c[N];
ll x;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; ll b;
    cin >> s >> b;
    if (b == 1) {
        cout << s << "\n";
        return 0;
    }
    if (s == "0") {
        cout << "0\n";
        return 0;
    }
    int sz(s.size());
    for (int i{}; i < sz; ++i) a[i] = s[i] - '0';
    for (int i{}; i < sz; ++i) {
        x = x * 10 + a[i];
        c[i] = x / b;
        x = x % b;
    }

    int i{};
    while (c[i] == 0) ++i;
    for (; i < sz; ++i) {
        cout << c[i];
    }
    cout << "\n";
    return 0;
}