#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k; cin >> k;
    ++k;
    string o;
    int i{1};
    while (cin >> o, o != "End") {
        // cout << "1";
        if (i % k == 0) {
            cout << o << "\n";
        } else {
            if (o == "Bu") {
                cout << "JianDao\n";
            } else if (o == "JianDao") {
                cout << "ChuiZi\n";
            } else {
                cout << "Bu\n";
            }
        }
        ++i;
    }

    return 0;
}
