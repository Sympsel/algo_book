#include <bits/stdc++.h>
using namespace std;

const int N = 353;
const int CNT = 41;
int f[CNT][CNT][CNT][CNT];
int sc[N];
int n;
int cnt[5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> n >> m;
    for (int i{1}; i <= n; ++i) cin >> sc[i];

    int card{};
    while (m--) {
        cin >> card;
        ++cnt[card];
    }

    f[0][0][0][0] = sc[1];
    for (int a{}; a <= cnt[1]; ++a) {
        for (int b{}; b <= cnt[2]; ++b) {
            for (int c{}; c <= cnt[3]; ++c) {
                for (int d{}; d <= cnt[4]; ++d) {
                    int i{1 + a + b * 2 + c * 3 + d * 4};
                    int& t{f[a][b][c][d]};
                    if (a) t = max(t, f[a - 1][b][c][d] + sc[i]);
                    if (b) t = max(t, f[a][b - 1][c][d] + sc[i]);
                    if (c) t = max(t, f[a][b][c - 1][d] + sc[i]);
                    if (d) t = max(t, f[a][b][c][d - 1] + sc[i]);
                }
            }
        }
    }
    cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << "\n";

    return 0;
}