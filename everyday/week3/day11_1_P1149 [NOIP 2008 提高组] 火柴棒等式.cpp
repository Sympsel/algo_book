#include <bits/stdc++.h>
using namespace std;

int a[10] {
    6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};

int cnt(int x) {
    if (x < 10) return a[x];
    int ret{};
    while (x) {
        ret += a[x % 10];
        x /= 10;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    n -= 4;

    int ret{};
    for (int i{}; i <= 1000; ++i) {
        for (int j{}; j <= 1000; ++j) {
            if (cnt(i) + cnt(j) + cnt(i + j) == n) {
                ++ret;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}
