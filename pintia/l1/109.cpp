#include <bits/stdc++.h>
using namespace std;

int a[26];
int cnt[26];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    for (int i{}; i < 26; ++i) cin >> a[i];

    for (auto& ch : str) {
        ++cnt[ch - 'a'];
    }
    int sum{};
    for (int i{}; i < 26; ++i) {
        if (i > 0) cout << " ";
        cout << cnt[i];
        sum += cnt[i] * a[i];
    }
    cout << "\n" << sum;


    return 0;
}