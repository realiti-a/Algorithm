#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> edges;
vector<int> visited;
int N, M, R;
void input() {
	cin >> N >> M >> R;

	edges = vector<vector<int>>(N + 1, vector<int>(0));
	visited = vector<int>(N + 1, 0);

	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}
}

int cnt = 0;

void dfs(int start) {
	for (int i = 0; i < edges[start].size(); i++) {
		int to = edges[start][i];

		if (visited[to]) continue;
		visited[to] = ++cnt;
		dfs(to);
	}
}

int main() {
	input();

	for (int i = 1; i <= N; i++) sort(edges[i].begin(), edges[i].end(), greater<int>());
	
	visited[R] = ++cnt;
	dfs(R);

	for (int i = 1; i <= N; i++) cout << visited[i] << "\n";
	return 0;
}