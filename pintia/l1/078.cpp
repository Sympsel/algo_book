#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string pro;
    cin.ignore();
    while (n--) {
        getline(cin, pro);
        bool isesay{pro.find("easy") != string::npos || pro.find("qiandao") != string::npos};
        if (isesay) continue;
        if (k == 0) {
            cout << pro;
            return 0;
        }
        k--;
    }
    cout << "Wo AK le";

    return 0;
}
