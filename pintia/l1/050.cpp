#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> A;
    int n, x;
    cin >> n >> x;
    x -= 1;
    int _x{x};
    string str(n, 'z');
    while (_x) {
        A.emplace_back(_x % 26);
        _x /= 26;
    }
    while (A.size() < n) A.emplace_back(0);

    // for (auto& _ : A) {
    //     cout << _ << " ";
    // }
    // cout << "\n";

    for (int i{n - 1}; i >= 0; --i) {
        str[i] -= A[n - 1 - i];
    }
    cout << str;

    return 0;
}
