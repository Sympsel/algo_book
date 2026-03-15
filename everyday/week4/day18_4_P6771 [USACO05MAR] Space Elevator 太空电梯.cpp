#include <bits/stdc++.h>
using namespace std;

const int N = 405;
int n, m{40000};
using ll = long long;
struct node {
    int h, a, c;
    node(int _h = 0,int _a = 0, int _c = 0) : h(_h),a(_a),c(_c) {}

    bool operator<(const node& o) const {
        return a < o.a;
    }
}A[N];

const int M = 4e4 + 7;
ll f[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int _1, _2, _3;
    for (int i{1}; i <= n; ++i) {
        cin >> _1 >> _2 >> _3;
        A[i] = {_1,_2,_3};
    }
    sort(A + 1, A + n + 1);

    for (int i{1}; i <= n; ++i) {
        auto& [h, a, c]{A[i]};
        for (int j{a}; j >= 0; --j) {
            for (int k{}; k <= c; ++k) {
                if (j >= k * h) {
                    f[j] = max(f[j], f[j - k * h] + k * h);
                }
            }
        }
    }

    ll ret{};
    for (int i{1}; i <= m; ++i) {
        ret = max(ret, f[i]);
    }
    cout << ret << "\n";
    return 0;
}
