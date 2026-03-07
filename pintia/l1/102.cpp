#include <bits/stdc++.h>
using namespace std;

const int N = 103;
int n;
double a[N];int cnt[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    int id, c;
    while (cin >> id >> c, id) {
        cnt[id] += c;
    }

    double sum{};
    cout << fixed << setprecision(2);
    for (int i{1}; i <= n; ++i) {
        sum += a[i] * cnt[i];
        cout << cnt[i] << "\n";
    }
    cout << sum;

    return 0;
}