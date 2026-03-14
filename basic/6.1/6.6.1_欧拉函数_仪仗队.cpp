#include <bits/stdc++.h>
using namespace std;

const int N = 4e4 + 7;
int n;
int p[N], cnt;
int phi[N];
bool st[N];

void sel() {
    phi[1] = 1;
    for (int i{2}; i <= n; ++i) {
        if (!st[i]) {
            phi[i] = i - 1;
            p[++cnt] = i;
        }
        for (int j{1}; 1ll * i * p[j] <= n; ++j) {
            int x{i * p[j]};
            st[x] = true;
            if (i % p[j] == 0) {
                phi[x] = p[j] * phi[i];
                break;
            }
            phi[x] = (p[j] - 1) * phi[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    sel();

    long long ret{};
    for (int i{1}; i < n; ++i) {
        ret += phi[i];
    }

    cout << ret * 2 + 1 << "\n";

    return 0;
}