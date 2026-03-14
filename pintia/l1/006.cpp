#include <bits/stdc++.h>
using namespace std;

int a[13];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    a[0] = 1;
    for (int i{1}; i < 13; ++i) a[i] = i * a[i - 1];
    // for (int i{1}; i < 13; ++i) cout << a[i] << " ";

    int ma{};
    for (int e{12}; e >= 1; --e) {
        int b{2};
        for (; a[e] / a[b - 1] > n; ++b) {}

        if (a[e] / a[b - 1] == n) {
            ma = max(ma, e - b + 1);
        }
    }
    cout << ma << "\n";

    return 0;
}