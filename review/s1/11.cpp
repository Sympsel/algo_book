#include <bits/stdc++.h>
using namespace std;

const int N = 1004;

int dx[N], dy[N], lx[N], ly[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> dx[i] >> dy[i] >> lx[i] >> ly[i];

    int x, y; cin >> x >> y;
    for (int i{n}; i >= 1; --i) {
        if (x >= dx[i] && y >= dy[i] && x <= dx[i] + lx[i] - 1 && y <= dy[i] + ly[i] - 1) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}