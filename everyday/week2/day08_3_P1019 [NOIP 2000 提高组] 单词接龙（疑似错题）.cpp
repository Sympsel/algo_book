#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a;
vector<int> cnt;


int check(const string& s1, const string& s2) {
    int sz1(s1.size()), sz2(s2.size());
    if (sz1 == 1 || sz2 == 1) return 0;
    int t(min(sz1, sz2));
    for (int i{1}; i < t; ++i) {
        if (s1.substr(sz1 - i, i) == s2.substr(0, i)) return i;
    }
    return 0;
}

string connect(const string& s1, const string& s2, int len) {
    return s1 + s2.substr(len);
}

int ret;

void dfs(const string s, int idx) {
    ret = max(ret, (int)s.size());
    if (idx == 2 * n) {
        return;
    }

    for (int i{}; i < n; ++i) {
        if (cnt[i] >= 2) continue;
        int len{check(s, a[i])};
        if (len) {
            ++cnt[i];
            dfs(connect(s, a[i], len), idx + 1);
            --cnt[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    cnt.resize(n, 0);
    for (int i{}; i < n; ++i)
        cin >> a[i];
    char ch; cin >> ch;
    for (int i{}; i < n; ++i) {
        if (a[i][0] == ch && a[i].size() > 1) {
            ++cnt[i];
            dfs(a[i], 1);
            --cnt[i];
        }
    }

    if (ret == 0) {
        for (int i = 0; i < n; ++i) {
            if (a[i][0] == ch) {
                ret = max(ret, (int)a[i].size());
            }
        }
    }

    cout << ret << "\n";

    return 0;
}
