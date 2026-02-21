#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x1, y1, d;
    d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b) {
        ll new_b{a % b};
        a = b;
        b = new_b;
    }
    return a;
}

int main() {
    int T; scanf("%d", &T);
    ll a, b, c;
    // 下标为1表示大于0的最小值，2表示当另一变量下标为1时的最大值
    ll x0, y0, x1, y1, x2, y2, k, dx, dy;
    while (T--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        // 系数化简
        ll d{gcd(gcd(a, b), c)};
        a /= d; b /= d; c /= d;

        ll g{exgcd(a, b, x0, y0)};
        if (c % g) {
            printf("-1\n");
            continue;
        }
        x0 = x0 / g * c;
        y0 = y0 / g * c;

        dx = b / g; dy = a / g;
        // 这里的x1, x2取正数不是自然数，因此值为0要加上dx或dy
        x1 = (x0 % dx + dx) % dx;
        x1 = x1 == 0 ? dx : x1;
        y2 = (c - a * x1) / b;
        y1 = (y0 % dy + dy) % dy;
        y1 = y1 == 0 ? dy : y1;
        x2 = (c - b * y1) / a;
        if (x2 <= 0 || y2 <= 0) {
            if (y2 <= 0) {
                printf("%lld ", x1);
            }
            if (x2 <= 0) {
                printf("%lld\n", y1);
            }
            continue;
        }
        ll cnt{(x2 - x1) / dx + 1};
        printf("%lld %lld %lld %lld %lld\n", cnt, x1, y1, x2, y2);
    }

    return 0;
}
