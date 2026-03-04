#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y; cin >> n;
    string name;
    while (n--) {
        cin >> name >> x >> y;
        if (x < 15 || x > 20 || y < 50 || y > 70)
            cout << name << "\n";
    }

    return 0;
}
