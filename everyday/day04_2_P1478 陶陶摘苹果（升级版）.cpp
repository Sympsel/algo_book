#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;
const int M = 1e3 + 4;
int n, s;
int f[M];
int pos;
int b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, d; cin >> n >> s >> d >> p;
    int h{d + p};
    int x, y;
    for (int i{1}; i <= n; ++i) {
        cin >> x >> y;
        if (x > h) continue;
        ++pos;
        b[pos] = y;
    }

    for (int i{1}; i <= pos; ++i)
        for (int j{s}; j >= b[i]; --j)
            f[j] = max(f[j], f[j - b[i]] + 1);
    cout << f[s] << "\n";

    return 0;
}
