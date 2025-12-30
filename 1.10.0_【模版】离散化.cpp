// #include <bits/stdc++.h>
// using namespace std;
// 
// const int N = 1e5 + 7;
// int n, a[N];
// 
// int pos;
// int disc[N];
// 
// int find(int x) {
	// int l{}, r{pos - 1};
	// while (l < r) {
		// int mid{(l + r) / 2};
		// if (disc[mid] >= x) r = mid;
		// else l = mid + 1;
	// }
	// return l;
// }
// 
// int main() {
	// ios::sync_with_stdio(false);
	// cout.tie(nullptr);
	// cin.tie(nullptr);
// 
	// cin >> n;
	// for (int i{}; i < n; ++i) {
		// cin >> a[i];
		// disc[pos++] = a[i];
	// }
// 	
	// sort(disc, disc + pos);
	// pos = unique(disc, disc + pos) - disc;
// 	
	// for (int i{}; i < n; ++i) {
		// cout << a[i] << ": " << find(a[i]) << endl;
	// }
// 	
// 
	// return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, a[N];

int disc[N];
unordered_map<int, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; ++i) {
		cin >> a[i];
	}
	
	sort(a, a + n);
	int id{};
	for (int i{}; i < n; ++i) {
		int x{a[i]};
		if (mp.count(x)) continue;
		mp[x] = id++;
	}
	
	for (int i{}; i < n; ++i) {
		cout << a[i] << ": " << mp[a[i]] << endl;
	}

	return 0;
}