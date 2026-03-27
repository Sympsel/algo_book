#include <bits/stdc++.h>
using namespace std;

vector<double> a, b;
vector<double> s;
int h1, h2;
const double EPS = 0.05;

void init() {
    int k; cin >> k;
    int e, c;
    cin >> e >> c;
    h1 = e;
    a.resize(h1 + 1);
    s.resize(h1 + 1);
    a[e] = c;
    while (--k) {
        cin >> e >> c;
        a[e] = c;
    }
    cin >> k;
    cin >> e >> c;
    h2 = e;
    b.resize(h2 + 1);
    b[e] = c;
    while (--k) {
        cin >> e >> c;
        b[e] = c;
    }
}

bool zero(double x) {
    return fabs(x) < EPS;
}

void solve() {
    for (int i{h1}; i >= h2; --i) {
        if (zero(a[i])) continue;
        double times{a[i] / b[h2]};
        if (zero(times)) {
            a[i] = 0;
            continue;
        }
        s[i - h2] = times;
        for (int j{}; j <= h2; ++j) {
            a[i - j] -= times * b[h2 - j];
        }

    }
    cout << fixed << setprecision(1);
    // 商
    int cntQ{};
    for (int i{h1 - h2}; i >= 0; --i) {
        if (!zero(s[i])) ++cntQ;
    }

    if (cntQ == 0) {
        cout << "0 0 0.0\n";
    } else {
        cout << cntQ;
        for (int i{h1 - h2}; i >= 0; --i) {
            if (!zero(s[i])) {
                cout << " " << i << " " << s[i];
            }
        }
        cout << "\n";
    }
    // 余
    int cntR{};
    for (int i{h2 - 1}; i >= 0; --i) {
        if (!zero(a[i])) ++cntR;
    }
    if (cntR == 0) {
        cout << "0 0 0.0\n";
    } else {
        cout << cntR;
        for (int i{h2 - 1}; i >= 0; --i) {
            if (!zero(a[i])) {
                cout << " " << i << " " << a[i];
            }
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solve();
    return 0;
}
