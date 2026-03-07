#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int cnt[N];

int getlast(int x) {
    int ct{};
    while (x >= 10) {
        int ret{1};
        while (x) {
            ret *= x % 10;
            x /= 10;
        }
        x = ret;
        ++ct;
    }
    return ct;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int b, e; cin >> b >> e;

    int ma{};
    for (int i{b}; i <= e; ++i) {
        int last{getlast(i)};
        cnt[i - b] = last;
        ma = max(ma, last);
    }
    cout << ma << "\n";
    bool flag{};
    for (int i{}; i <= e - b; ++i) {
        if (ma == cnt[i]) {
            if (flag) {
                cout << " ";
            } else {
                flag = true;
            }
            cout << (i + b);
        }
    }

    return 0;
}