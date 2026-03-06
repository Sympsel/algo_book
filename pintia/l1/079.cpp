#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i{}; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int mi{a[0]};
    int ma{a.back()};
    int x{}, y{};
    for (int i{}; i < n; ++i) {
        if (mi == a[i]) ++x;
        else break;
    }
    for (int i{n - 1}; i >= 0; --i) {
        if (ma == a[i]) ++y;
        else break;
    }
    cout << mi << " " << x << "\n" << ma << " " << y;

    return 0;
}