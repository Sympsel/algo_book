#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    double ret{1.f * n * k / 10};
    cout << fixed << setprecision(2) << ret;

    return 0;
}
