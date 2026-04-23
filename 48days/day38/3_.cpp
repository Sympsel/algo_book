#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
using ll = long long;

int n, k;
ll a[N];
ll ret;

// void dfs(int idx, ll sum) {
void dfs() {
    stack<pair<int, ll>> st;
    st.emplace(1, a[1]);
    while (st.size()) {
        auto [idx, sum]{st.top()};
        if (sum % k == 0) {
            ret = max(ret, sum);
        }
        st.pop();
        for (int i{idx + 1}; i <= n; ++i) {
            st.emplace(i, a[i] + sum);
        }
    }
    // if (sum % k == 0) {
    //     ret = max(ret, sum);
    // }
    // for (int i{idx}; i <= n; ++i) {
    //     dfs(i + 1, sum + a[i]);
    // }
}

int main() {
    cin >> n >> k;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n, [](const ll& x, const ll& y) {
        return y < x;
    });
    dfs();
    cout << ret << "\n";
    return 0;
}