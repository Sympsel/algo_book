#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    cout << setfill('0');
    if (t < 100000) {
        int x{t / 100};
        if (x < 22) cout << 20;
        else cout << 19;
        cout << setw(2) << x << "-" << setw(2) << to_string(t % 100);
    } else {
        cout << t / 100 << "-" << setw(2) << to_string(t % 100);
    }

    return 0;
}
