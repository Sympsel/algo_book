#include <bits/stdc++.h>
using namespace std;

const int N = 103;
int a[N], n;
bool st[N];
vector<int> g[N];
int pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        a[i] *= 10;
    }

    int cnt{};
    while (true) {
        if (cnt >= n - 1) {
            break;
        }
        int mi{0x3f3f3f};
        for (int i{1}; i <= n; ++i) {
            if (!st[i] && mi > a[i]) {
                mi = a[i];
            }
        }
        int sum{};
        for (int i{1}; i <= n; ++i) {
            if (!st[i]) ++sum;
        }
        // int unst_idx{};
        // for (int i{1}; i <= n; ++i) {
        //     if (!st[i]) {
        //         unst_idx = i;
        //         break;
        //     }
        // }
        // for (int i{unst_idx}; i < sum * mi + unst_idx; ++i) {
        for (int i{}; i < sum * mi; ++i) {
            if (!st[i + 1]) {
                g[i % sum + 1].emplace_back(++pos);
            }
        }
        for (int i{1}; i <= n; ++i) {
            if (mi == a[i] && !st[i]) {
                st[i] = true;
                ++cnt;
            }
        }
    }

    if (cnt == n - 1) {
        int unst_idx{}, ma_idx{};
        for (int i{1}; i <= n; ++i) {
            if (!st[i]) unst_idx = i;
            else if (a[i] > a[ma_idx]) ma_idx = i;
            else {}
        }
        for (int i{}; i < a[unst_idx] - a[ma_idx]; i += 2) {
            pos += 2;
            g[ma_idx].emplace_back(pos);
        }
    }

    for (int i{1}; i <= n; ++i) {
        cout << "#" << i << "\n";
        for (int j{}; j < a[i]; ++j) {
            if (j && j % 10 != 0) cout << " ";
            cout << g[i][j];
            if ((j + 1) % 10 == 0 && j) cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}