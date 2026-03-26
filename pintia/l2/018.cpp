#include <bits/stdc++.h>
using namespace std;

vector<double> a, b;
// vector<double> s, r;
int h1, h2;

void init() {
    int k; cin >> k;
    int e, c;
    cin >> e >> c;
    h1 = e;
    a.resize(h1 + 1);
    // s.resize(h1 + 1);
    a[e] = c;
    while (--k) {
        cin >> e >> c;
        a[e] = c;
    }
    cin >> k;
    cin >> e >> c;
    h2 = e;
    b.resize(h2 + 1);
    // r.resize(h2 + 1);
    b[e] = c;
    while (--k) {
        cin >> e >> c;
        b[e] = c;
    }
}

bool zero(double x) {
    return fabs(x) < 1e-17;
}

// void put_if(double x) {

// }

void solve() {
    for (int i{h1}; i >= h2; --i) {
        if (zero(a[i])) continue;
        double times{a[i] / b[h2]};
        // cout << times << "\n";
        for (int j{}; j <= h2; ++j) {
            a[i - j] -= times * b[h2 - j];
            // cout << a[i - j] << "\n";
        }

    }
    // for (int i{h1 - h2}; i >= 0; --i) {
    //     cout << " " << i << " " << a[i];
    // }
    // cout << "\n";
    for (int i{h1}; i >= 0; --i) {
        cout << " " << i << " " << a[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solve();
    return 0;
}
