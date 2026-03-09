#include <bits/stdc++.h>
using namespace std;

string str;
const int mask = (1 << 5) - 1;
int readln() {
    cin >> str;
    int ret{};
    for (int i{}; i < 5; ++i) {
        if (str[i] == '0') {
            ret |= (1 << (4 - i));
        }
    }
    return ret;
}

int cnt1(int x) {
    int ret{};
    while (x) {
        ++ret;
        x &= (x - 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    int a[6];
    int b[6];
    while (t--) {
        int ret{7};
        memset(a, 0, sizeof a);
        for (int i{}; i < 5; ++i) {
            a[i] = readln();
        }

        for (int st{}; st < (1 << 5); ++st) {
            memcpy(b, a, sizeof a);
            int push{st};
            int cnt{};
            for (int i{}; i < 5; ++i) {
                cnt += cnt1(push);
                if (cnt > 6) {
                    goto next;
                }
                b[i] = b[i] ^ push ^ (push << 1) ^ (push >> 1);
                b[i + 1] ^= push;
                b[i] &= mask;
                push = b[i];
            }
            if (b[4] == 0) ret = min(ret, cnt);
            next:;
        }
        if (ret > 6) {
            cout << "-1\n";
        } else {
            cout << ret << "\n";
        }
    }

    return 0;
}