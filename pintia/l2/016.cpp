#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
unordered_map<int, pair<int, int>> mp;
bool man[N];

// BFS收集五代内的所有亲属（包括旁系）
unordered_set<int> getRelatives(int start) {
    unordered_set<int> relatives;
    queue<pair<int, int>> q;  // <当前节点, 当前深度>
    q.push({start, 1});  // 自己算第1代
    relatives.insert(start);

    while (!q.empty()) {
        auto [cur, depth] = q.front();
        q.pop();

        if (depth >= 5) continue;  // 只收集五代以内

        auto it = mp.find(cur);
        if (it != mp.end()) {
            int fid = it->second.first;
            int mid = it->second.second;

            // 添加父母并继续遍历
            if (fid != -1 && !relatives.count(fid)) {
                relatives.insert(fid);
                q.push({fid, depth + 1});
            }
            if (mid != -1 && !relatives.count(mid)) {
                relatives.insert(mid);
                q.push({mid, depth + 1});
            }
        }
    }

    return relatives;
}

void query() {
    int x, y;
    cin >> x >> y;

    // 检查性别
    if (man[x] == man[y]) {
        cout << "Never Mind\n";
        return;
    }

    // 获取x的五代内所有亲属
    unordered_set<int> xRelatives = getRelatives(x);

    // 获取y的五代内所有亲属，并检查是否有重叠
    queue<pair<int, int>> q;
    q.push({y, 1});

    while (!q.empty()) {
        auto [cur, depth] = q.front();
        q.pop();

        if (depth >= 5) continue;

        // 检查当前节点是否在x的亲属中（且不是x或y本身）
        if (xRelatives.count(cur) && cur != x && cur != y) {
            cout << "No\n";
            return;
        }

        auto it = mp.find(cur);
        if (it != mp.end()) {
            int fid = it->second.first;
            int mid = it->second.second;

            if (fid != -1) q.push({fid, depth + 1});
            if (mid != -1) q.push({mid, depth + 1});
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    memset(man, false, sizeof(man));

    for (int i = 0; i < n; ++i) {
        int id, fid, mid;
        char gen;
        cin >> id >> gen >> fid >> mid;

        // 标记性别
        if (gen == 'M') man[id] = true;

        // 存储父母信息
        mp[id] = {fid, mid};

        // 重要：标记父母的性别
        if (fid != -1) man[fid] = true;   // 父亲是男性
        if (mid != -1) man[mid] = false;  // 母亲是女性
    }

    int q;
    cin >> q;
    while (q--) {
        query();
    }

    return 0;
}
