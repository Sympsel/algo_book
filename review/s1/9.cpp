#include <bits/stdc++.h>
using namespace std;

const int N = 2004;
int c[N * 2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2; cin >> s1 >> s2;
    if (s1 == "0" || s2 == "0") {
        cout << "0\n";
        return 0;
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int sz1(s1.size()), sz2(s2.size());
    for (int i{}; i < sz1; ++i) {
        for (int j{}; j < sz2; ++j) {
            c[i + j] += (s1[i] - '0') * (s2[j] - '0');
        }
    }

    for (int i{}; i < sz1 + sz2; ++i) {
        if (c[i] > 9) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }

    int sz{sz1 + sz2};
    while (c[sz] == 0 && sz > 0) --sz;
    for (int i{sz}; i >= 0; --i) cout << c[i];
    cout << "\n";

    return 0;
}