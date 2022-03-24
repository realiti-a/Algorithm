#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> visited;
int N, M, K;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int dy = y + dr[i];
		int dx = x + dc[i];
		if (dy < 0 || dy >= N) continue;
		if (dx < 0 || dx >= M) continue;
		if (visited[dy][dx]) continue;
		if (!map[dy][dx]) continue;
		dfs(dy, dx);
	}
}

int dfsAll() {
	int component = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (visited[y][x]) continue;
			if (!map[y][x]) continue;
			dfs(y, x);
			component++;
		}
	}
	return component;
}

void input() {
	cin >> M >> N >> K;

	map = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> x >> y;
		map[y][x] = 1;
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		input();
		cout << dfsAll() << "\n";
	}
	
	return 0;
}