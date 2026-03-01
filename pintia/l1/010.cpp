#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    // sort(a, a + 3);
    int mi{a[0]}, ma{a[0]}, sum{};
    for (int i{}; i < 3; ++i) {
        if (a[i] < mi) mi = a[i];
        if (a[i] > ma) ma = a[i];
        sum += a[i];
    }
    cout << mi << "->" << sum - ma - mi << "->" << ma;

    return 0;
}
