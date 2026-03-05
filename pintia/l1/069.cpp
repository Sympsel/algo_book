#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[5];
    int _max{};
    for (int i{1}; i <= 4; ++i) {
        cin >> a[i];
        if (a[i] > _max) _max = a[i];
    }
    int _min, diff; cin >> _min >> diff;

    int flag{};
    int x{};
    for (int i{1}; i <= 4; ++i) {

        if (a[i] < _min || _max - a[i] > diff) {
            ++flag;
            x = i;
        }
    }

    if (flag == 0) cout << "Normal";
    else if (flag == 1) cout << "Warning: please check #" << x << "!";
    else cout << "Warning: please check all the tires!";

    return 0;
}
