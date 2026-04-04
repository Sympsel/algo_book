#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt{n};
    for (int i{1}; i <= n; ++i) {
        int x; cin >> x;
        if (x ==1) --cnt;
    }
    cout << cnt << endl;
    return 0;
}
