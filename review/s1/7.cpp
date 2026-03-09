#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int a[N];
int b[N];
int c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2; cin >> s1 >> s2;
    int la(s1.size()), lb(s2.size());
    for (int i{la - 1}; i >= 0; --i) {
        a[la - i - 1] = s1[i] - '0';
    }
    for (int i{lb - 1}; i >= 0; --i) {
        b[lb - i - 1] = s2[i] - '0';
    }
    int sz{max(la, lb)};
    for (int i{}; i < sz; ++i) {
        c[i] += a[i] + b[i];
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }

    if (c[sz] > 10) {
        c[sz + 1] += c[sz] / 10;
        c[sz] %= 10;
    }

    ++sz;
    while (c[sz] == 0 && sz > 0) {
        sz--;
    }
    for (int i{sz}; i >= 0; --i) {
        cout << c[i];
    }
    cout << "\n";
    return 0;
}