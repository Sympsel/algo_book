#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +6;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k{};
    int n; cin >> n;
    int a[N];
    for (int i{}; i < n; ++i) {
        cin >> a[i];
        if (a[i] == i) ++k;
    }
    if (k == n) {
        cout << n << "\n";
        return 0;
    }

    for (int i{}; i < n - 1; ++i) {
        if (a[i] != i && a[a[i]] == i) {
            cout << (k + 2) << "\n";
            return 0;
        }
    }
    cout << k + 1 << "\n";

    return 0;
}