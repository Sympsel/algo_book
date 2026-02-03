#include <bits/stdc++.h>
using namespace std;

const int N = 3e3;

struct Cow {
	int a, b;
}cow[N];

struct Gen {
	int val, cnt;
}gen[N];

int c, l;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> c >> l;
	for (int i{}; i < c; ++i) cin >> cow[i].a >> cow[i].b;
	for (int i{}; i < l; ++i) cin >> gen[i].val >> gen[i].cnt;
	
	sort(cow, cow + c, [](const Cow& a, const Cow& b) {
		return a.a > b.a;
	});
	
	sort(gen, gen + l, [](const Gen& a, const Gen& b) {
		return a.val > b.val;
	});
	
	int ret{};
	for (int i{}; i < c; ++i)
		for (int j{}; j < l; ++j) {
			if (gen[j].val >= cow[i].a && gen[j].val <= cow[i].b && gen[j].cnt) {
				++ret;
				--gen[j].cnt;
				break;
			}
		}
	cout << ret << "\n";

	return 0;
}