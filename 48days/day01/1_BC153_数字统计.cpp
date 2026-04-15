#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt2(int x) {
    int ret{};
    while (x) {
        if (x % 10 == 2) ++ret;
        x /= 10; 
    }
    return ret;
}

int main() {
    int l, r;
    cin >> l >> r;
    ll ret{};
    for (int i{l}; i <= r; ++i) {
        ret += cnt2(i);
    }
    cout << ret << "\n";
    return 0;
}
