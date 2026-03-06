#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    string cur;
    while (t--) {
        cin >> cur;
        int a{1};
        int ret{};
        for (int i{n - 1}; i >= 0; --i) {
            if (cur[i] == 'n') ret += a;
            a = a * 2;
        }
        cout << (ret + 1) << "\n";
    }

    return 0;
}
