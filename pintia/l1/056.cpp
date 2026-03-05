#include <bits/stdc++.h>
using namespace std;

using p = pair<string, int>;
const int N = 1e4 + 4;
p a[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    string name; int num;
    int sum{};
    for (int i{1}; i <= n; ++i) {
        cin >> name >> num;
        a[i].first = name;
        a[i].second = num;
        sum += num;
    }

    int havg{sum / n / 2};
    int mi{}, m{0x3f3f3f3f};
    for (int i{1}; i <= n; ++i) {
        auto& [_name, _num]{a[i]};
        if (abs(havg - _num) < m) {
            m = abs(havg - _num);
            mi = i;
        }
    }
    cout << havg << " " << a[mi].first;

    return 0;
}
