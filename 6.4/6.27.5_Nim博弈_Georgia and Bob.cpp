#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i{1}; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i{n}; i >= 1; --i)
            a[i] = a[i] - a[i - 1] - 1;
        int s{};
        for (int i{n}; i >= 1; i -= 2)
            s ^= a[i];
        if (s) cout << "Georgia will win" << endl;
        else cout << "Bob will win" << endl;
    }

    return 0;
}