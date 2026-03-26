#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int s1{}, s2{};
    for (int i{1}; i <= n / 2; ++i) {
        // cout << a[i] << " \n"[i == n / 2];
        s1 += a[i];
    }
    for (int i{n / 2 + 1} ; i <= n; ++i) {
        // cout << a[i] << " \n"[i == n];
        s2 += a[i];
    }
    if (n % 2 == 0) {
        cout << "Outgoing #: " << n / 2 << "\n";
        cout << "Introverted #: " << n /2 << "\n";
        cout << "Diff = " << s2 - s1 << "\n";
        return 0;
    }
    int ret{s2 - s1};
    s1 = 0, s2 = 0;
    for (int i{1}; i <= n /2 + 1; ++i) {
        s1 += a[i];
    }
    for (int i{n / 2 + 2}; i <= n; ++i) {
        s2 += a[i];
    }
    if (ret < s2 - s1) {
        cout << "Outgoing #: " << n / 2 << "\n";
        cout << "Introverted #: " << n /2 + 1 << "\n";
        ret = s2 - s1;
    } else {
        cout << "Outgoing #: " << n / 2 + 1 << "\n";
        cout << "Introverted #: " << n /2 << "\n";
    }
    cout << "Diff = " << ret<< "\n";
    return 0;
}
