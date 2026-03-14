#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int K = 105;
using kv = pair<int, int>;
vector<kv> p[K];
int m, n;
int f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    int k{};
    int x, y, z;
    for (int i{1}; i <= n; ++i) {
        cin >> x >> y >> z;
        p[z].emplace_back(x, y);
        k = max(k, z);
    }

    for (int i{1}; i <= k; ++i)
        for (int j{m}; j >= 0; --j)
            for (auto [x, y] : p[i])
                if (j >= x)
                    f[j] = max(f[j], f[j - x] + y);
    cout << f[m] << "\n";

    return 0;
}
