#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 103;
ll a[N], b[N];
int n;

ll gcd(ll x, ll y) {
    x = abs(x); y = abs(y);
    if (x < y) swap(x, y);
    while (y) {
        ll new_y{x % y};
        x = y;
        y = new_y;
    }
    return x;
}

ll lcm(ll x, ll y) {
    if (x == 0 || y == 0) return 0;
    x = abs(x); y = abs(y);
    return x / gcd(x, y) * y;
}

void add(ll a, ll b, ll& sa, ll& sb) {
    if (b == 0) return;

    ll a1, b1;
    ll ta{a * sb + b * sa};
    ll tb{b * sb};
    ll m{gcd(ta, tb)};
    sa = ta / m;
    sb = tb / m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    char ch;
    for (int i{1}; i <= n; ++i)
        cin >> a[i] >> ch >> b[i];

    ll retA{}, retB{1};
    for (int i{1}; i <= n; ++i) {
        if (b[i] == 0) continue;
        add(a[i], b[i], retA, retB);
    }
    ll u{retA / retB};
    if (u) cout << u;
    retA %= retB;
    if (u && retA) cout << " ";
    if (retA) cout << retA << "/" << retB;
    if (!u && !retA) cout << "0";

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// const int N = 103;
// ll a[N], b[N];
// int n;

// ll gcd(ll x, ll y) {
//     x = abs(x); y = abs(y);
//     if (x < y) swap(x, y);
//     while (y) {
//         ll new_y{x % y};
//         x = y;
//         y = new_y;
//     }
//     return x;
// }

// ll lcm(ll x, ll y) {
//     if (x == 0 || y == 0) return 0;
//     x = abs(x); y = abs(y);
//     return x / gcd(x, y) * y;
// }

// void add(ll a, ll b, ll& sa, ll& sb) {
//     if (b == 0) return;
//     ll m{lcm(b, sb)};
//     ll t{m / b * a + m / sb * sa};
//     ll d{gcd(t, m)};
//     sa = t / d;
//     sb = m / d;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n;
//     char ch;
//     for (int i{1}; i <= n; ++i) {
//         cin >> a[i] >> ch >> b[i];
//         cout << a[i] << "/" << b[i] << " ";
//     }
//     cout << "\n";

//     ll retA{}, retB{1};
//     for (int i{1}; i <= n; ++i) {
//         if (b[i] == 0) continue;
//         add(a[i], b[i], retA, retB);
//     }
//     ll u{retA / retB};
//     if (u) cout << u;
//     retA %= retB;
//     if (u && retA) cout << " ";
//     if (retA) cout << retA << "/" << retB;
//     if (!u && !retA) cout << "0";

//     return 0;
// }
