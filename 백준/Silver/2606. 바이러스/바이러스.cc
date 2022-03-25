#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<int> visited;

int infect(int now) {
	int count = 1;
	visited[now] = 1;
	for (int to = 1; to <= N; to++) {
		if (visited[to]) continue;
		if (!map[now][to]) continue;
		count += infect(to);
	}
	return count;
}

void input() {
	int u, v;
	cin >> N >> M;

	map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	visited = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}
}

int main() {
	input();
	cout << infect(1) - 1;

	return 0;
}