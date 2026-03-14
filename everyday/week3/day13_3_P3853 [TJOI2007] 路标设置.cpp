#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 7;
int L, n, k;
int a[N];
int b[N];

bool check(int x) {
    int cnt{};
    for (int i{1}; i <= n; ++i) {
        cnt += b[i] / x;
        if (b[i] % x == 0) --cnt;
        if (cnt > k) return false;
    }
    return cnt <= k;
}

int main() {
    cin >> L >> n >> k;
    int _; cin >> _;
    --n;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    sort(b + 1, b + 1 + n, [](const int& x, const int& y) {return x > y;});
    int l{1}, r{L};
    while (l < r) {
        int mid{(l + r) / 2};
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";

    return 0;
}
