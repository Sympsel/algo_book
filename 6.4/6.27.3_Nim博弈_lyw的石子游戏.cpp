#include <iostream>
using namespace std;
const int N = 1e5 + 3;
int n;
int a[N];

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i{n - 1}; i >= 0; --i)
            cin >> a[i];
        int s{};
        for (int i{1}; i < n; i += 2)
            s ^= a[i];
        if (s) cout << "lyw" << endl;
        else cout << "zgc" << endl;
    }



    return 0;
}
