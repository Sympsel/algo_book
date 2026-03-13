#include <bits/stdc++.h>
using namespace std;

void tolow(string& s) {
    for (int i{}; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
}

bool depend(const string& str, size_t pos, int len) {
    if (pos > 0 && str[pos - 1] != ' ') return false;
    if (pos + len < str.size() && str[pos + len] != ' ') return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word, str;
    cin >> word;
    cin.ignore();
    getline(cin, str);
    int sz(str.size());
    tolow(word); tolow(str);
    int len(word.size());
    size_t pos{str.find(word)};
    if (pos == string::npos) {
        cout << "-1\n";
        return 0;
    }
    int cnt{};
    pos = 0;
    int ret{-1};
    while ((pos = str.find(word, pos)) != string::npos) {
        if (depend(str, pos, len)) {
            ++cnt;
            if (ret == -1) ret = pos;
        }
        ++pos;
    }
    if (cnt == 0) cout << "-1\n";
    else cout << cnt << " " << ret << "\n";
    return 0;
}
