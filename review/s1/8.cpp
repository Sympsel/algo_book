#include <bits/stdc++.h>
using namespace std;

const int N = 10100;
int a[N], b[N], c[N];

int cmp(const string& s1, const string& s2) {
    int sz1(s1.size()), sz2(s2.size());
    if (sz1 == sz2) {
        for (int i{}; i < sz1; ++i) {
            if (s1[i] > s2[i]) return 1;
            else if (s1[i] < s2[i]) return -1;
            else{}
        }
        return 0;
    }
    return sz1 > sz2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2; cin >> s1 >> s2;
    int ret{cmp(s1, s2)};
    if (ret == 0) {
        cout << "0\n";
        return 0;
    }
    if (ret < 0) {
        swap(s1, s2);
        cout << "-";
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int len1(s1.size()), len2(s2.size());
    for (int i{}; i < len1; ++i) a[i] = s1[i] - '0';
    for (int i{}; i < len2; ++i) b[i] = s2[i] - '0';

    for (int i{}; i < len1; ++i) {
        c[i] += a[i] - b[i];
        if (c[i] < 0) {
            c[i] += 10;
            --c[i + 1];
        }
    }

    while (c[len1] == 0 && len1 > 0) {
        --len1;
    }
    for (int i{len1}; i >= 0; --i) cout << c[i];
    cout << "\n";

    return 0;
}