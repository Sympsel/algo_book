#include <bits/stdc++.h>
using namespace std;

int a, b;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> n;
    int x1, y1, x2, y2;
    int cnta{}, cntb{};
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        int sum{x1 + x2};
        if (sum == y1 && sum == y2 || sum != y1 && sum != y2) continue;
        if (sum == y1) ++cnta;
        else ++cntb;
        if (cnta > a) {
            cout << "A\n" << cntb << "\n";
            return 0;
        } else if (cntb > b) {
            cout << "B\n" << cnta << "\n";
            return 0;
        } else {}
    }


    return 0;
}
