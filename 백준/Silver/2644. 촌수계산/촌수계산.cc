#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int visited[101];
int start, last, N;
queue<int> relatives;

void input() {
	cin >> N;
	cin >> start >> last;
	relatives.push(start);

	int m, child, parent;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> parent >> child;
		map[child][parent] = 1;
		map[parent][child] = 1;
	}
}

int bfs() {
	while (!relatives.empty()) {
		int now = relatives.front();
		relatives.pop();

		for (int to = 1; to <= N; to++) {
			if (!map[now][to]) continue;
			if (visited[to] || to == start) continue;

			relatives.push(to);
			visited[to] = visited[now] + 1;
			if (to == last) {
				return visited[to];
			}
		}
	}
	return -1;
}

int main() {
	input();
	cout << bfs() << "\n";
	return 0;
}