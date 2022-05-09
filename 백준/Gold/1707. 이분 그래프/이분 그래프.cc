#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> edges;
vector<int> visited;
int V, E;
void input() {
	cin >> V >> E;

	edges = vector<vector<int>>(V + 1, vector<int>());
	visited = vector<int>(V + 1, 0);

	int from, to;
	for (int i = 0; i < E; i++) {
		cin >> from >> to;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < edges[now].size(); i++) {
			int to = edges[now][i];

			if (visited[to]) continue;

			if (visited[now] == 1) {
				visited[to] = 2;
				q.push(to);
			}
			else if (visited[now] == 2) {
				visited[to] = 1;
				q.push(to);
			}
		}
	}
}

int isOkay() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < edges[i].size(); j++) {
			if (visited[i] == visited[edges[i][j]]) return 0;
		}
	}
	return 1;
}

int main() {
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		input();

		for (int j = 1; j <= V; j++) {
			if (visited[j]) continue;
			bfs(j);
		}

		if (isOkay()) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}