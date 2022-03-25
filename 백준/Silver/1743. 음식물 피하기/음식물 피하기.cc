#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> visited;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int dfs(int y, int x) {
	int now = 1;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int dy = y + dr[i];
		int dx = x + dc[i];
		if (dy < 0 || dy >= N) continue;
		if (dx < 0 || dx >= M) continue;
		if (visited[dy][dx]) continue;
		if (!map[dy][dx]) continue;
		now += dfs(dy, dx);
	}
	return now;
}

int dfsAll() {
	int maxSize = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (visited[y][x]) continue;
			if (!map[y][x]) continue;
			int nowSize = dfs(y, x);
			if (nowSize > maxSize) maxSize = nowSize;
		}
	}
	return maxSize;
}

void input() {
	int K;

	cin >> N >> M >> K;

	map = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		map[y - 1][x - 1] = 1;
	}
}

int main() {
	input();
	cout << dfsAll();
	return 0;
}