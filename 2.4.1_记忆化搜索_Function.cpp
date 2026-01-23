#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll x, y, z;
struct Node {
	ll a, b, c;
	Node(ll _a = 0, ll _b = 0, ll _c = 0) : a(_a), b(_b), c(_c) {};
	
	bool operator==(const Node& other) const {
		return a == other.a && b == other.b && c == other.c; 
	}
};

struct NodeHash {
    size_t operator()(const Node& node) const {
        return hash<ll>()(node.a) ^ hash<ll>()(node.b) ^ hash<ll>()(node.c);
    }
};

unordered_map<Node, ll, NodeHash> mp;

ll w(ll a, ll b, ll c) {
	Node node(a, b, c);
	if (mp.count(node))
		return mp[node];
	
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	
	ll ret = 0;
	if (a > 20 || b > 20 || c > 20)
		ret = w(20, 20, 20);
	else if (a < b && b < c) 
		ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else 
		ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return mp[node] = ret;
}

int main() {
	
	while(true) {
		cin >> x >> y >> z;
		if (x == -1 && y == -1 && z == -1) break;
		printf("w(%lld, %lld, %lld) = %lld\n", x, y, z, w(x, y, z));
	}

	return 0;
}