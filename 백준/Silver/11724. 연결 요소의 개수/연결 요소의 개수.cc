#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<int> visited;
int N, M;

void dfs(int now) {
	visited[now] = 1;
	
	for (int i = 0; i < map[now].size(); i++) {
		int to = map[now][i];
		if (visited[to]) continue;
		dfs(to);
	}
}

int dfsAll() {
	int component = 0;
	
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		dfs(i);
		component++;
	}

	return component;
}

void input() {
	int u, v;
	cin >> N >> M;

	map = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}
}

int main() {
	input();
	cout << dfsAll() << "\n";
	return 0;
}