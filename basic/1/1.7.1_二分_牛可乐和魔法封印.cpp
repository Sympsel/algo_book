#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

int n, q;
int a[N]{0};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; ++i) cin >> a[i];
    
    cin >> q;
    int x, y;
    while (q--) {
        cin >> x >> y;
        int l{}, r{n - 1};
        while (l < r) {
            int mid{l + (r - l) / 2};
            if (a[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (a[n - 1] < x) {
            cout << 0 << "\n";
            continue;
        }
        
        int _{l};
        
        l = 0, r = n - 1;
        while (l <r) {
            int mid{l + (r - l) / 2 + 1};
            if (a[mid] <= y) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (a[0] > y) {
            cout << 0 << "\n";
            continue;
        }
        cout << l - _ + 1 << "\n";
    }
	

	return 0;
}