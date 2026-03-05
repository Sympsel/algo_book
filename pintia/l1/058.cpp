#include <bits/stdc++.h>
using namespace std;

bool isdig(const string& s) {
    for (const auto& ch : s) {
        if (ch != '6') return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);
    int n{1};
    for (auto& ch : str) {
        if (ch == ' ') ++n;
    }
    string word;
    stringstream ss(str);
    while (ss >> word, n--) {
        if (isdig(word)) {
            if (word.size() > 9) cout << 27;
            else if (word.size() > 3) cout << 9;
            else cout << word;
        } else {
            cout << word;
        }
        if (n > 0) cout << " ";
    }

    return 0;
}
