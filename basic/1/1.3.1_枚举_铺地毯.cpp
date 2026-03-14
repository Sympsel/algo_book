#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 3;

int X[N];
int Y[N];
int dX[N];
int dY[N];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i{}; i < n; ++i) {
        cin >> X[i] >> Y[i] >> dX[i] >>dY[i];
    }

    int x, y;
    cin >>x >> y;
    for (int i{n - 1}; i >= 0; --i) {
        if (x >= X[i] && x <= X[i] + dX[i] && y >= Y[i] && y <= Y[i] + dY[i]) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}