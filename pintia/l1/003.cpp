#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string num;
    cin >> num;
    for (int i{}; i < num.size(); ++i) {
        ++cnt[num[i] - '0'];
    }

    for (int i{}; i < 10; ++i)
        if (cnt[i])
            cout << i << ":" << cnt[i] << "\n";

    return 0;
}