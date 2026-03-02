#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string num;
    cin >> num;
    double ret{1.0};
    if (num[0] == '-') {
        ret *= 1.5;
        num = num.substr(1, num.size());
    }
    int cnt2{};
    for (auto& ch : num)
        if (ch == '2') ++cnt2;

    ret *= 1.f * cnt2 / num.size();
    if ((num[num.size() - 1] - '0') % 2 == 0) ret *= 2;
    ret *= 100;
    cout << fixed << setprecision(2) << ret << "%" << "\n";

    return 0;
}
