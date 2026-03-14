#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 7;
int n;
int da[N];
int ne[N];
int head;

unordered_set<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> head >> n;
    int u, v, w;
    while (n--) {
        cin >> u >> w >> v;
        da[u] = w;
        ne[u] = v;
    }
    st.emplace(abs(da[head]));
    int pre{head};

    int rmhead{-1};
    int rmtail{-1};

    for (int cur{ne[head]}; cur != -1; ) {
        int val{abs(da[cur])};
        if (st.count(val)) {
            int tmp{ne[cur]};

            ne[pre] = ne[cur];

            if (rmhead == -1) {
                rmhead = rmtail = cur;
            } else {
                ne[rmtail] = cur;
                rmtail = cur;
            }
            ne[cur] = -1;
            cur = tmp;
        } else {
            st.emplace(val);
            pre = cur;
            cur = ne[cur];
        }
    }

    cout << setfill('0');

    for (int cur{head}; cur != -1; cur = ne[cur]) {
        cout << setw(5) << cur << " " << da[cur] << " ";
        if (ne[cur] != -1) cout << setw(5) << ne[cur] << "\n";
        else cout << "-1\n";
    }

    for (int cur{rmhead}; cur != -1; cur = ne[cur]) {
         cout << setw(5) << cur << " " << da[cur] << " ";
        if (ne[cur] != -1) cout << setw(5) << ne[cur] << "\n";
        else cout << "-1\n";
    }

    return 0;
}