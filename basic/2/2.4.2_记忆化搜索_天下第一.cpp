#include <bits/stdc++.h>
using namespace std;

int n, p;

struct Hash {
	size_t operator()(const pair<int, int>& _) const {
		return hash<int>()(_.first) ^ hash<int>()(_.second);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> p;
	int x, y;
	while (n--) {
		unordered_set<pair<int, int>, Hash> st;
		cin >> x >> y;
		st.emplace(x, y);
		while (true) {
			if (x == 0) {
                cout << "1\n";
                break;
            }
            
            if (y == 0) {
                cout << "2\n";
                break;
            }
			
			int newX = (x + y) % p;
			int newY = (newX + y) % p;
			
			
			pair<int, int> curr = {newX, newY};
			
			if (st.count(curr)) {
				cout << "error\n";
				break;
			}
			st.insert(curr);
			x = newX;
			y = newY;
		}
	}
	
	return 0;
}