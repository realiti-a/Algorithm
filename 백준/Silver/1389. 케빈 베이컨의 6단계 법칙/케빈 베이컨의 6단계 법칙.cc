#include <iostream>
#include <queue>
#include <vector>
#define INF 10000
using namespace std;

vector<vector<int>> edges;
int N, M;
void input() {
	cin >> N >> M;
	edges = vector<vector<int>>(N + 1, vector<int>());

	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}
}

int bfs(int start) {
	vector<int> visited(N + 1, 0);

	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < edges[now].size(); i++) {
			int to = edges[now][i];

			if (visited[to]) continue;
			visited[to] = visited[now] + 1;
			q.push(to);
		}
	}
	
	int sum = 0;

	for (int i = 1; i <= N; i++) {
		sum += visited[i] - 1;
	}
	
	return sum;
}
int main() {
	input();

	int minValue = 100000, index = 0;
	for (int i = 1; i <= N; i++) {
		int sum = bfs(i);
		if (sum < minValue) {
			minValue = sum;
			index = i;
		}
	}

	cout << index << "\n";
	return 0;
}