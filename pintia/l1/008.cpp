#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int b, e;
    cin >> b >> e;
    long long s((b + e) * (e - b + 1) / 2);
    int id{1};
    for (int i{b}; i <= e; ++i, ++id) {
        cout << setw(5) << i;
        if (id % 5 == 0 || i == e) cout << "\n";
    }
    cout << "Sum = " << s;

    return 0;
}