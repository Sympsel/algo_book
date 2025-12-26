#include <iostream>
using namespace std;

const int N = 1e6 + 7;

int da[N], ne[N], id, head;
int mp[N];

int op, x, y;
int main() {
	
	++id;
	da[id] = 1;
	mp[1] = id;
	
	int q; cin >> q;
	
	
	while (q--) {
		cin >> op >> x;
		int p = mp[x];
		if (op == 1) {
			cin >> y;
			++id;
			da[id] = y;
			mp[y] = id;
			ne[id] = ne[p];
			ne[p] = id;
			
		} else if (op == 2) {
			cout << da[ne[p]] << "\n";
		} else {
			if (ne[p]) {
				mp[da[ne[p]]] = 0;
				ne[p] = ne[ne[p]];
			}
		}
	}
	
	return 0;
}