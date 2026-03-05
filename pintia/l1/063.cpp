#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    char g; int h, w;
    while (t--) {
        cin >> g >> h >> w;
        if (g == '0') {
            if (h > 129) cout << "ni li hai! ";
            else if (h < 129) cout << "duo chi yu! ";
            else cout << "wan mei! ";
            if (w < 25) cout << "duo chi rou!\n";
            else if (w > 25) cout << "shao chi rou!\n";
            else cout << "wan mei!\n";
        } else {
            if (h > 130) cout << "ni li hai! ";
            else if (h < 130) cout << "duo chi yu! ";
            else cout << "wan mei! ";
            if (w < 27) cout << "duo chi rou!\n";
            else if (w > 27) cout << "shao chi rou!\n";
            else cout << "wan mei!\n";
        }
    }

    return 0;
}