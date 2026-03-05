#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    double _;
    double ret{};
    for (int i{}; i < n; ++i) {
        cin >> _;
        ret += (1 / _);
    }
    ret = n / ret;
    cout << fixed << setprecision(2) << ret;

    return 0;
}