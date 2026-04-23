#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<char> st;
    string s; cin >> s;
    for (int i{}; i < (int)s.size(); ++i) {
        if (st.empty() || st.back() != s[i]) {
            st.emplace_back(s[i]);
        } else {
            st.pop_back();
        }
    }
    if (st.empty()) {
        cout << "0";
        return 0;
    }
    for (auto& c : st) {
        cout << c;
    }
    return 0;
}
