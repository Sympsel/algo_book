#include <bits/stdc++.h>
using namespace std;

vector<string> a, b;
vector<pair<string, char>> c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    char g;
    cin >> n;
    string name;
    for (int i{}; i < n; ++i) {
        cin >> g >> name;
        if (g == '1') a.emplace_back(name);
        else b.emplace_back(name);
        c.emplace_back(name, g);
    }

    int i{n / 2}, j{n / 2}, k{};
    while (k < n / 2) {
        auto [name, g]{c[k++]};
        cout << name << " ";
        if (g == '1') cout << b[--j] << "\n";
        else cout << a[--i] << "\n";
    }

    return 0;
}
