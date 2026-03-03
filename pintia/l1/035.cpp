#include <bits/stdc++.h>
using namespace std;

vector<string> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string name;
    bool f1{}, f2{};
    while (cin >> name, name != ".") {
        a.emplace_back(name);
        if (a.size() == 2) f1 = true;
        if (a.size() == 14) f2 = true;
    }

    if (f1 && f2) {
        cout << a[1] << " and " << a[13] << " are inviting you to dinner...";
    } else if (f1) {
        cout << a[1] << " is the only one for you...";
    } else cout << "Momo... No one is for you ...";

    return 0;
}
