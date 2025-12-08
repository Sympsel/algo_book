#include <bits/stdc++.h>
using namespace std;

const int 1e9 + 7;

void delSubStr(string& str, const string& s) {
	size_t pos{};
	while ((pos = str.find(s, pos)) != string::npos) {
		str.erase(pos,s.size());
		if (pos > 0) {
			--pos;
		}
	}
}

long long catalan(int n) {
    if (n <= 1) return 1;
    
    vector<long long> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    
    return dp[n];
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	string str; cin >> str;
	
	delSubStr(str, "()");
	
	// cout << str << endl;
	cout << catalan(str.size()) << endl;
	return 0;
}