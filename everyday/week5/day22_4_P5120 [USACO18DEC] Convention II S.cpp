#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n;
struct node {
    int id, a, t;
    node(int _id = 0, int _a = 0, int _t = 0) : id(_id), a(_a), t(_t) {}

    bool operator<(const node& o) const {
        return id > o.id;
    }
}arr[N];

bool cmp(const node& x, const node& y) {
    return x.a < y.a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int a, t;
    for (int i{1}; i <= n; ++i) {
        cin >> a >> t;
        arr[i] = {i, a, t};
    }
    sort(arr + 1, arr + 1 + n, cmp);

    int cur{}, ret{}, i{1};
    priority_queue<node> q;
    while (i <= n || q.size()) {
        while (i <= n && cur >= arr[i].a) q.emplace(arr[i++]);
        if (q.empty()) q.emplace(arr[i++]);

        auto [id, a, t]{q.top()}; q.pop();
        if (cur <= a) {
            cur = a + t;
        } else {
            ret = max(ret, cur - a);
            cur += t;
        }
    }

    cout << ret << "\n";

    return 0;
}