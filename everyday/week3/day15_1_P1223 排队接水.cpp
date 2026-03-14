#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
using ll = long long;
int n;

struct node {
    ll id, w;
    node(ll _id = 0, ll _w = 0) : id(_id), w(_w) {}
    bool operator<(const node& o) const {
        if (w == o.w) return id < o.id;
        return w < o.w;
    }
}a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll id, w;
    for (int i{1}; i <= n; ++i) {
        cin >> w;
        a[i] = {i, w};
    }

    sort(a + 1, a + n + 1);
    ll ret{};
    ll sum{};
    for (int i{1}; i <= n; ++i) {
        auto& [id, w]{a[i]};
        cout << id << " ";
        ret += sum;
        sum += w;
    }
    cout << "\n";
    cout << fixed << setprecision(2) << 1.f * ret / n << "\n";

    return 0;
}
