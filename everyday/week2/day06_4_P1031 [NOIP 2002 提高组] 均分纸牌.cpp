#include <bits/stdc++.h>
using namespace std;

const int N = 104;
int n;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int sum{};
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    int avg{sum / n};
    int cnt{};
    for (int i{1}; i < n; ++i) {
        if (a[i] == avg) continue;
        a[i + 1] += a[i] - avg;
        a[i] = avg;
        ++cnt;
    }
    if (a[n] != avg) ++cnt;
    cout <<


    return 0;
}