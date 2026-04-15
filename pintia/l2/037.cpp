#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int N = 110;
const int M = 1010;
int n, m, s;
queue<char> q[N];
stack<char> st;

int main() {
    cin >> n >> m >> s;
    for (int i{1}; i <= n; ++i) {
        for (int j{}; j < m; ++j) {
            char c; cin >> c;
            q[i].emplace(c);
        }
    }

    vector<char> ret;
    int op;
    while (cin >> op, op != -1) {
        if (op == 0) {
            if (st.size()) {
                ret.emplace_back(st.top());
                st.pop();
            }
        } else {

            if (q[op].size()) {
                if ((int)st.size() == s) {
                    ret.emplace_back(st.top());
                    st.pop();
                }
                st.emplace(q[op].front());
                q[op].pop();
            }
        }
    }
    for (auto ch : ret) {
        cout << ch;
    }

    return 0;
}