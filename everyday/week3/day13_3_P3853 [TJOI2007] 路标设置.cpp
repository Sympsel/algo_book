#include <bits/stdc++.h>
using namespace std;

int len, n, k;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> len >> n >> k;
    int _;
    for (int i{1}; i <= n; ++i) {
        cin >> _;
        a.emplace_back(_);
    }
    sort(a.begin(), a.end());
    n = a.size();
    // for (auto x : a) {
    //     cout << x << " ";
    // }
    // cout << "\n";

    priority_queue<int> q;
    for (int i{1}; i < n; ++i) {
        q.emplace(a[i] - a[i - 1]);
    }

    while (k-- && q.size()) {
        auto sz{q.top()}; q.pop();
        // cout << sz << "\n";
        if (sz <= 1) {
            continue;
        }
        q.emplace(sz / 2);
        if (sz % 2 == 1) {
            q.emplace(sz / 2 + 1);
        }
    }
    cout << q.top() << "\n";

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// const int L = 1e7 + 3;
// const int N = 1e5 + 7;
// int len, n, k;



// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> len >> n >> k;


//     return 0;
// }