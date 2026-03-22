#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
pair<int, string> a[N];

int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i{}; i < n; ++i)
        cin >> a[i].first >> a[i].second;

    bool sign{};
    int cnt;
    int cur{};
    while (m--) {
        const auto& [face, name]{a[cur]};
        cin >> sign >> cnt;
        if (!face && sign || face && !sign) {
            cur = (cur + cnt) % n;
        } else {
            cur = (cur - cnt + n) % n;
        }
    }
    cout << a[cur].second << "\n";
    return 0;
}
