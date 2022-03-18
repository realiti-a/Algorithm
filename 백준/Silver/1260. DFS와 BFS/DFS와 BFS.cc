#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> used;
vector<vector<int>> graph;

int N, M, V;
int from, to;

void input() {
	cin >> N >> M >> V;
	graph = vector<vector<int>>(N + 1, vector<int>());

	for (int i = 0; i < M; i++) {
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	for (int i = 0; i < graph.size(); i++) {
		sort(graph[i].begin(), graph[i].end());
	}
}

void dfs(int now) {
	cout << now << " ";
	for (int i = 0; i < graph[now].size(); i++) {
		int to = graph[now][i];
		if (used[to]) continue;
		used[to] = 1;
		dfs(to);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i = 0; i < graph[now].size(); i++) {
			int to = graph[now][i];
			if (used[to]) continue;
			used[to] = 1;
			q.push(to);
		}
	}
}

int main() {
	input();

	used = vector<int>(N + 1, 0);
	used[V] = 1;
	dfs(V);
	cout << "\n";
	
	used = vector<int>(N + 1, 0);
	used[V] = 1;
	bfs(V);
	cout << "\n";

	return 0;
}