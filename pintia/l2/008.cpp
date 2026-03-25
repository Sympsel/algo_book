#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n;
string s;
int ret{1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    getline(cin, s);
    n = s.size();
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i{}; i < n; ++i) {
        int l{i}, r{i};
        while (l >= 0 && r < n && s[l] == s[r]) {
            ret = max(ret, r - l + 1);
            --l, ++r;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            ret = max(ret, r - l + 1);
            --l, ++r;
        }
    }
    cout << ret << "\n";
    return 0;
}
