#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
int N;
int MAX = 0, maxCount = 0;
vector<vector<int>> visited;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void dfs(int y, int x, int height) {
	visited[y][x] = 1;
	
	for (int i = 0; i < 4; i++) {
		int dy = y + dr[i];
		int dx = x + dc[i];

		if (dy < 0 || dy >= N) continue;
		if (dx < 0 || dx >= N) continue;

		if (visited[dy][dx]) continue;
		if (map[dy][dx] < height) continue;
		
		dfs(dy, dx, height);
	}
}

int dfsAll(int height) {
	int component = 0;
	visited = vector<vector<int>>(N, vector<int>(N, 0));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x]) continue;
			if (map[y][x] < height) continue;

			dfs(y, x, height);
			component++;
		}
	}

	return component;
}

void input() {
	cin >> N;
	map = vector<vector<int>>(N, vector<int>(N, 0));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] > MAX) MAX = map[y][x];
		}
	}
}

int main() {
	input();
	
	for (int i = 1; i <= MAX; i++) {
		int count = dfsAll(i);
		if (count > maxCount) maxCount = count;
	}

	cout << maxCount << "\n";
	return 0;
}