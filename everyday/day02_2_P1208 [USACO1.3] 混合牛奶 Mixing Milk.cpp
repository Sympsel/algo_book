#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e3 + 7;
#define f a[i].first
#define s a[i].second
using p = pair<int, int>;
p a[N];
int tar, n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tar >> n;
    for (int i{1}; i <= n; ++i)
        cin >> f >> s;

    sort(a + 1, a + n + 1, [](const p& x, const p& y) {
        return x.first < y.first;
    });

    int cur{};
    ll cost{};
    int i{1};
    while (cur + s < tar) {
        cur += s;
        cost += f * s;
        ++i;
    }

    cost += (tar - cur) * f;
    cout << cost << "\n";
    return 0;
}
