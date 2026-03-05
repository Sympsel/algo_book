#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[10];
    for (int i{}; i < 10; ++i) {
        cin >> a[i];
    }
    int x; cin >> x; x += 30;
    int ret{};
    for (int i{}; i < 10; ++i)
        if (x >= a[i])
            ++ret;
    cout << ret << "\n";
    return 0;
}
