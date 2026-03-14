#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 3;
int a[N];

int main() {
    int n; cin >> n;
    int s{};
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        s ^= a[i];
    }

    if (s == 0) {
        cout << "lose" << endl;
        return 0;
    }

    // int k{};
    // for (int i{30}; i >= 0; --i) {
    //     if ((s >> i) & 1) {
    //         k = i;
    //         break;
    //     }
    // }

    // for (int i{1}; i <= n; ++i) {
    //     if ((a[i] >> k) & 1) {
    //         cout << (a[i] - (a[i] ^ s)) << " " << i << endl;
    //         a[i] ^= s;
    //         break;
    //     }
    // }

    for (int i{1}; i <= n; ++i) {
        if ((a[i] ^ s) < a[i]) {
            cout << (a[i] - (a[i] ^ s)) << " " << i << endl;
            a[i] ^= s;
            break;
        }
    }
    for (int i{1}; i <= n; ++i)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
