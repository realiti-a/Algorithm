#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edges;
int N, root, removeNode, leafCnt;

void input() {
	cin >> N;
	edges = vector<vector<int>>(N);
	leafCnt = 0;
	int parent;
	for (int i = 0; i < N; i++) {
		cin >> parent;
		if (parent == -1) root = i;
		else {
			edges[parent].push_back(i);
		}
	}
	cin >> removeNode;
}

void dfs(int now) {
	int flag = 0;
	for (int i = 0; i < edges[now].size(); i++) {
		int to = edges[now][i];
		
		if (to == removeNode) continue;
		flag = 1;
		dfs(to);
	}
	if (!flag) leafCnt++;
}

int main() {
	input();
	if(removeNode != root) dfs(root);
	cout << leafCnt << "\n";
	return 0;
}