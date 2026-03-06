#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, l;
    cin >> x >> y >> l;
    vector<int> a;
    a.emplace_back(x);
    a.emplace_back(y);
    for (int i{}; i < l; ++i) {
        int pro{a[i] * a[i + 1]};
        if (i > 0) cout << " ";
        cout << a[i];
        if (pro < 10) a.emplace_back(pro);
        else {
            a.emplace_back(pro / 10);
            a.emplace_back(pro % 10);
        }
    }

    return 0;
}