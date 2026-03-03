#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int h;
    double w;
    while (n--) {
        cin >> h >> w;
        double w0{1.f * (h - 100) * 1.8};
        double dw{w - w0};
        if (abs(dw) < w0 * 0.1) {
            cout << "You are wan mei!\n";
        } else {
            if (dw > 0) cout << "You are tai pang le!\n";
            else cout << "You are tai shou le!\n";
        }
    }

    return 0;
}
