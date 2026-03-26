#include <bits/stdc++.h>
using namespace std;

// const int N = 1e4 + 7;
int k, n, m;

priority_queue<double, vector<double>, greater<double>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> n >> m;
    int _;
    while(k--) {
        int _max{}, _min{0x3f3f3f3f};
        int sum{};
        for (int i{1}; i <= n; ++i) {
            cin >> _;
            sum += _;
            _max = max(_max, _);
            _min = min(_min, _);
        }
        sum -= _max + _min;
        double avg{1.0 * sum / (n - 2)};
        if (q.size() < m) {
            q.emplace(avg);
        } else {
            if (avg > q.top()) {
                q.pop();
                q.emplace(avg);
            }
        }
    }
    bool is_first{true};
    cout << fixed << setprecision(3);
    while (q.size()) {
        if (!is_first) cout << " ";
        else is_first = false;
        cout << q.top();
        q.pop();
    }
    return 0;
}
