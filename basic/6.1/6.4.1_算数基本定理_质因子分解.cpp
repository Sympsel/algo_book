#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 3;
int n;
int cnt[N];

void deprime(int x) {
    for (int i{2}; i <= n / i; ++i) {
        int c{};
        while (x % i == 0) {
            ++c;
            x /= i;
        }
        cnt[i] += c;
    }
    if (x > 1) ++cnt[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{2}; i <= n; ++i) {
        deprime(i);
    }

    for (int i{2}; i <= n; ++i)
        if (cnt[i])
            cout << i << " " << cnt[i] << "\n";

    return 0;
}