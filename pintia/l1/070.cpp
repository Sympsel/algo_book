#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    string tar{"chi1 huo3 guo1"};
    int total{};
    int first{};
    int obj{};
    while (getline(cin, line), line != ".") {
        ++total;
        auto it{search(line.begin(), line.end(), tar.begin(), tar.end())};
        if (it == line.end()) continue;
        ++obj;
        if (first == 0) first = total;
    }

    cout << total << "\n";
    if (first == 0) cout << "-_-#";
    else cout << first << " " << obj;

    return 0;
}