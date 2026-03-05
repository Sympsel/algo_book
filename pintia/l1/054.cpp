#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
string a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char ch; int n;
    cin >> ch >> n;
    string _;
    cin.ignore();
    for (int i{1}; i <= n; ++i) {
        getline(cin, _);
        replace(_.begin(), _.end(), '@', ch);
        a[i] = _;
    }
    bool flag{};
    for (int i{1}; i <= n / 2; ++i) {
        if (a[i] != a[n + 1 - i] && !flag) {
            flag = true;
        }
    }
    if (!flag) {
        cout << "bu yong dao le\n";
    }
    for (int i{n}; i >= 1; --i) {
        reverse(a[i].begin(), a[i].end());
        cout << a[i] << "\n";
    }

    return 0;
}
