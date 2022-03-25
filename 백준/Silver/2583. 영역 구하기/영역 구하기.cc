#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> visited;
vector<int> res;

int N, M, K;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int dfs(int y, int x) {
	int now = 1;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int dy = y + dr[i];
		int dx = x + dc[i];
		if (dy < 0 || dy >= M) continue;
		if (dx < 0 || dx >= N) continue;
		if (visited[dy][dx]) continue;
		if (map[dy][dx]) continue;
		now += dfs(dy, dx);
	}
	return now;
}

void dfsAll() {
	int component = 0;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x]) continue;
			if (visited[y][x]) continue;
			res.push_back(dfs(y, x));
		}
	}
}

void fill(int x1, int y1, int x2, int y2) {
	for (int y = y1; y < y2; y++) {
		for (int x = x1; x < x2; x++) {
			map[y][x] = 1;
		}
	}
}

void input() {
	cin >> M >> N >> K;

	map = vector<vector<int>>(M, vector<int>(N, 0));
	visited = vector<vector<int>>(M, vector<int>(N, 0));

	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		fill(x1, y1, x2, y2);
	}
}

int main() {
	input();
	
	dfsAll();
	sort(res.begin(), res.end());
	
	cout << res.size() << "\n";

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
	
	return 0;
}