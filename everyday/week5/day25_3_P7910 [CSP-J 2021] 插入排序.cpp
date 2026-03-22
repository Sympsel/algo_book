#include <bits/stdc++.h>
using namespace std;

const int N = 8e3 + 7;
pair<int, int> a[N];
pair<int, int> b[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int _;
    for (int i{1}; i <= n; ++i) {
        cin >> _;
        a[i] = {_, i};
    }

    int op;
    int x, y;
    for (int i{1}; i <= n; ++i) {
        for (int j{i}; j >= 2; --j) {
            if (a[j].first < a[j - 1].first) {
                swap(a[j], a[j - 1]);
            }
        }
    }
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            for (int i{1}; i <= n; ++i) {
                if (a[i].second == x) {
                    a[i].first = y;
                    bool flag{};
                    for (int j{i}; j >= 2; --j) {
                        if (a[j].first < a[j - 1].first ||
                            a[j].first == a[j - 1].first && a[j].second < a[j - 1].second) {
                            swap(a[j], a[j - 1]);
                            flag = true;
                        } else break;
                    }
                    if (flag) break;
                    for (int j{i}; j < n; ++j) {
                        if (a[j].first > a[j + 1].first ||
                            a[j].first == a[j + 1].first && a[j].second > a[j + 1].second) {
                            swap(a[j], a[j + 1]);
                        } else break;
                    }
                    break;
                }
            }
        } else if (op == 2) {
            cin >> x;
            for (int i{1}; i <= n; ++i) {
                if (a[i].second == x) {
                    cout << i << "\n";
                    break;
                }
            }
        } else {}
    }
    return 0;
}
