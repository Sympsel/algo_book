#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, N; char ch;
    cin >> N >> ch;

    n = sqrt((N + 1) / 2);
    int ret{N - n * n * 2 + 1};
    for (int i{n}; i > 0; --i) {
        for (int j{n - i}; j > 0; --j)
            cout << " ";
        for (int j{}; j < 2 * i - 1; ++j)
            cout << ch;
        cout << "\n";
    }

    for (int i{2}; i <= n; ++i) {
        for (int j{n - i}; j > 0; --j)
            cout << " ";
        for (int j{}; j < 2 * i - 1; ++j)
            cout << ch;
        cout << "\n";
    }

    cout << ret << "\n";
    return 0;
}
