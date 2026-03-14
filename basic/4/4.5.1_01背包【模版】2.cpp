#include <bits/stdc++.h>
using namespace std;

const int N = 1007;
int v[N], w[N], n, m;
int f[N];
const int INF = -0x3f;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i{1}; i <= n; ++i)
        cin >> v[i] >> w[i];

    for (int i{1}; i <= n; ++i)
        for (int j{m}; j >= v[i]; --j)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << "\n";


    memset(f, INF, sizeof f);
    f[0] = 0;
    for (int i{1}; i <= n; ++i) {
        for (int j{m}; j >= v[i]; --j) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << max(f[m], 0) << "\n";

    return 0;
}
