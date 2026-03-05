#include <bits/stdc++.h>
using namespace std;

void tolow(string& s) {
    for (auto& ch : s) {
        if (ch >= 'A' && ch <= 'Z') {
            if (ch == 'I') continue;
            ch += 32;
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<char> sign;
    sign.emplace(':');
    sign.emplace(',');
    sign.emplace('.');
    sign.emplace('!');
    sign.emplace(';');

    int t; cin >> t;
    string line;
    cin.ignore();
    string word;
    while (t--) {
        vector<string> a;
        getline(cin, line);
        cout << line << "\n";
        replace(line.begin(), line.end(), '?', '!');
        stringstream ss(line);
        while (ss >> word) {
            if (word != "I") {
                tolow(word);
            }
            int b{};
            for (int i{}; i < (int)word.size(); ++i) {
                if (sign.count(word[i])) {
                    a.emplace_back(word.substr(b, i));
                    string tmp;
                    tmp += word[i];
                    a.emplace_back(tmp);
                    b = i + 1;
                }
            }
            string tmp2{word.substr(b, word.size())};
            if (!tmp2.empty())
                a.emplace_back(tmp2);
            // if (sign.count(word.back())) {
            //     // char _{word.back()};
            //     // word.pop_back();
            //     // a.emplace_back(word);
            //     // string tmp;
            //     // tmp += _;
            //     // a.emplace_back(tmp);
            // } else {
            //     a.emplace_back(word);
            // }
        }

        int sz(a.size());
        for (int i{}; i < sz - 1; ++i) {
            if (a[i] == "can" && a[i + 1] == "you") {
                a[i] = "I"; a[i + 1] = "can";
            }
            if (a[i] == "could" && a[i + 1] == "you") {
                a[i] = "I"; a[i + 1] = "could";
            }
        }


        for (int i{}; i < sz; ++i) {
            if (a[i] == "I" || a[i] == "me") {
                if (i + 1 < sz && (a[i + 1] == "can" || a[i + 1] == "could"))
                    continue;
                a[i] = "you";
            }
        }

        cout << "AI: ";
        for (int i{}; i < sz; ++i) {
            if (i > 0 && !sign.count(a[i][0])) {
                if (!(i + 1 < sz && sign.count(a[i + 1][0])))
                    cout << " ";
            }
            cout << a[i];
        }
        cout << "\n";

        for (int i{}; i < (int)a.size(); ++i) {
            if (t == 0)
            cout << a[i] << "-";
        }
        if (t == 0) cout << "\n";
    }

    return 0;
}
