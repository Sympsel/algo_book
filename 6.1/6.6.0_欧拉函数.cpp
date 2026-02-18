#include <bits/stdc++.h>
using namespace std;

int phi(int x) {
    int ret{n};
    for (int i{2}; i <= n / i; ++i) {
        if (n % i == 0) {
            ret = ret / i * (i - 1);
            while( % i == 0) n /= i;

        }
    }
    if (x > 1) ret = ret / x + (x - 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    return 0;
}