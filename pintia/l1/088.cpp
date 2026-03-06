#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, k, tar;
int a[N];
int b[N];
int pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> tar;
    int _a, _b;
    for (int i{1}; i <= n; ++i) {
        cin >> _a >> _b;
        if (_a < 175) continue;
        ++pos;
        a[pos] = _a; b[pos] = _b;
    }


    return 0;
}