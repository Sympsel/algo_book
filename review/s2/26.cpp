#include <iostream>
using namespace std;

const int N = 1e6 + 7;


/*
	第一纬表示节点编号，第二位维表示当前字符的映射
	存的内容表示即将通往的节点编号
*/
int tr[N][26];
// 经过某节点的次数；以某节点为结尾的次数
int p[N], e[N];
int idx; // 当前节点数

void insert(string& s) {
	int cur{}; // 从根节点开始
	// 根节点经过次数加1
	++p[cur];

	for (auto ch : s) {
		int path = ch - 'a';
		// 如果没有路，创建新的节点
		if (tr[cur][path] == 0) tr[cur][path] = ++idx;
		// 现在有路了，迭代cur
		cur = tree[cur][path];
		++p[cur];
	}
	// 循环结束，在插入的末尾标记次数加1
	++e[cur];
}

#define TIMES = 1
#define PRE = 2

// int fd(string& s) {
// 	int cur{};
// 	for (auto ch : s) {
// 		int path = ch - 'a';
// 		if (tr[cur][path] == 0) return 0;
// 		cur = tr[cur][path];
// 	}
// 	return e[cur];
// }

// int fd_pre(string& s) {
// 	int cur{};
// 	for (auto ch : s) {
// 		int path = ch - 'a';
// 		if (tr[cur][path] == 0) return 0;
// 		cur = tr[cur][path];
// 	}
// 	return p[cur];
// }
int fd(string& s, char flag) {
	int cur{};
	for (auto ch : s) {
		int path = ch - 'a';
		if (tr[cur][path] == 0) return 0;
		cur = tr[cur][path];
	}
	if (flag == TIMES) return e[cur]; 
	if (flag == PRE) return p[cur];
	return -1;
}

int main() {

	return 0;
}