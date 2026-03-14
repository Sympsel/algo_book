#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, c;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> c;
    for (int i{n}; i >= 1; --i) {
        cin >> a[i];
    }
    int cnt{1};
    for (int i{2}; i <= n; ++i) {
        if (a[i - 1] - a[i] <= c) ++cnt;
        else {
            cout << cnt << "\n";
            return 0;
        }
    }
    cout << cnt << "\n";


    return 0;
}