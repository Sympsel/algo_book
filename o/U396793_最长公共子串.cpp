#include <bits/stdc++.h>
using namespace std;

string matchStr(const string& str1, const string& str2) {
    int ml{};
    int mb{};
    for (int i{}; i < str1.size(); ++i) {
        for (int j{}; j < str2.size(); ++j) {
            int l{};
			
            for (int k{}; k < min((int)str1.size(), (int)str2.size()) - i; ++k) {
                if (str1[i + k] == str2[j + k]) {
                    ++l;
                    if (l > ml) {
                        ml = l;
                        mb = i;
                    }
                } else {
                    break;
                }
            }
        }
    }
    return str1.substr(mb, ml);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cout << matchStr("1AB2345CD", "12345EF") << endl;
	

    return 0;
}