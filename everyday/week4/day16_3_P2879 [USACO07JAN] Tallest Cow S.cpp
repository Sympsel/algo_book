#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
int n, maxI, maxH, R;
set<pair<int, int>> st;
int f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> maxI >> maxH >> R;
    int l, r;
    while (R--) {
        cin >> l >> r;
        if (l > r) swap(l, r);
        st.emplace(l, r);
    }

    f[1] = maxH;
    for (auto& [l, r] : st) {
        --f[l + 1];
        ++f[r];
    }
    for (int i{1}; i <= n; ++i) {
        f[i] += f[i - 1];
        cout << f[i] << "\n";
    }

    return 0;
}
