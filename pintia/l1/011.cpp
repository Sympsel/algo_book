#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    unordered_set<char> s;
    for (auto& ch : str2)
        s.emplace(ch);

    for (auto& ch : str1)
        if (!s.count(ch))
            cout << ch;
    cout << "\n";

    return 0;
}
