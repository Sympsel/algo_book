#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s;
    string ta, tb; cin >> ta >> tb;
    int a{}, b{};
    int ret{n + 1};
    for (int i{1}; i <= n; ++i) {
        cin >> s;
        if (s == ta) a = i;
        if (s == tb) b = i;
        if (a && b) ret = min(ret, abs(a - b));
    }
    cout << ( (ret == n + 1) ? -1 : ret ) << "\n";
    return 0;
}
