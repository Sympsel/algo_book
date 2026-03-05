#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        vector<string> a;
        vector<string> b;
        string word;
        while (cin >> word, word.back() != ',') {
            a.emplace_back(word);
        }
        a.emplace_back(word);
        while (cin >> word, word.back() != '.') {
            b.emplace_back(word);
        }
        b.emplace_back(word);
        int sa(a.back().size()), sb(b.back().size());
        if (sa < 4 || sb < 4 ||
            a.back().substr(sa - 4, sa) != "ong," ||
            b.back().substr(sb - 4, sb) != "ong.") {
            cout << "Skipped\n";
            continue;
        } else {
            for (int i{}; i < (int)a.size(); ++i) {
                if (i > 0) cout << " ";
                cout << a[i];
            }
            int sz(b.size());
            for (int i{}; i < sz - 3; ++i) {
                cout << " " << b[i];
            }
            cout << " qiao ben zhong.\n";
        }

    }

    return 0;
}
