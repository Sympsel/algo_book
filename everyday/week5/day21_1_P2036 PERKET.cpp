#include <bits/stdc++.h>
using namespace std;

const int N = 14;
int a[N];
int b[N];
int n;

int A{1}, B{};
int ret{0x3f3f3f3f};

void dfs() {
    for (int st{1}; st < (1 << n); ++st) {
        A = 1, B = 0;
        for (int i{1}, tmp{st}; tmp; ++i, tmp >>= 1) {
            if (tmp & 1) {
                A *= a[i];
                B += b[i];
            }
        }
        ret = min(ret, abs(A - B));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i] >> b[i];
    dfs();
    cout << ret << "\n";
    return 0;
}
