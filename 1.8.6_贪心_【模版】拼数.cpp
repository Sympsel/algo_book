#include <bits/stdc++.h>
using namespace std;

const int N = 23;
int n;
string nums[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	
	function<bool(const string& s1, const string& s2)> f = [](const string& s1, const string& s2) {
		string a = s1 + s2;
		string b = s2 + s1;
		for (int i{}; i < a.size(); i++) {
			if (a[i] > b[i]) return true;
			if (a[i] < b[i]) return false;
		}
		return false;
	};

	cin >> n;
	for (int i{}; i < n; i++) cin >> nums[i];
	sort(nums, nums + n, f);
	for (int i{}; i < n; i++) cout << nums[i];
	cout << "\n";

	return 0;
}