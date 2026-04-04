#include <iostream>
using namespace std;

using  ll = long long;

ll a[3];
ll b[3];
ll k;
int main() {
    ll T; cin >> T;
    while (T--) {
        ll* arr = a, *brr = b;
            cin >> arr[0] >> arr[1] >> arr[2];
        cin >> k;
        while (k--) {
            brr[0] = (arr[1] + arr[2]) / 2;
            brr[1] = (arr[0] + arr[2]) / 2;
            brr[2] = (arr[0] + arr[1]) / 2;
            if (brr[0] == brr[1] && brr[1] == brr[2] && brr[0] == brr[1]) {
                cout << brr[0] << " " << brr[1] << " " << brr[2] << endl;
                goto next;
            }
            swap(arr, brr);
        }
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        next:;
    }
    return 0;
}
