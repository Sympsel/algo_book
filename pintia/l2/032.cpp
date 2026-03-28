#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n, k;
int a[N];

bool query() {
    int cnt{};
    stack<int> st;
    int pre{};
    for (int i{1}; i <= n; ++i) {
        if (pre + 1 != a[i]) {
            st.emplace(a[i]);
            cnt = max(cnt, (int)st.size());
            if (cnt > k) return false;
        } else {
            ++pre;
        }

        while (st.size() && pre + 1 == st.top()) {
            st.pop();
            ++pre;
        }
    }
    return st.empty() && cnt <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> n >> k >> T;
    while (T--) {
        for (int i{1}; i <= n; ++i) cin >> a[i];

        if (query()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
