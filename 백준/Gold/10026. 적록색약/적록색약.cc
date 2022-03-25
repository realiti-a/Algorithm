#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> visited;
char map[100][101];
int N;
int regionR, regionB, regionG, regionRG;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void dfs(int y, int x, char c) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int dy = y + dr[i];
		int dx = x + dc[i];

		if (dy < 0 || dy >= N) continue;
		if (dx < 0 || dx >= N) continue;

		if (visited[dy][dx]) continue;
		if (map[dy][dx] != c) continue;
		dfs(dy, dx, c);
	}
}

void dfsRG(int y, int x) {
	visited[y][x] = 2;
	for (int i = 0; i < 4; i++) {
		int dy = y + dr[i];
		int dx = x + dc[i];

		if (dy < 0 || dy >= N) continue;
		if (dx < 0 || dx >= N) continue;

		if (visited[dy][dx] == 2) continue;
		if (map[dy][dx] == 'B') continue;
		dfsRG(dy, dx);
	}
}

void dfsAll() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x]) continue;

			if (map[y][x] == 'R') regionR++;
			else if (map[y][x] == 'G') regionG++;
			else if (map[y][x] == 'B') regionB++;
			dfs(y, x, map[y][x]);
		}
	}
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == 2) continue;
			if (map[y][x] == 'B') continue;
			regionRG++;
			dfsRG(y, x);
		}
	}
}

void input() {
	cin >> N;
	
	visited = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	regionR = 0, regionB = 0, regionG = 0, regionRG;
}

int main() {
	input();
	
	dfsAll();
	
	cout << regionR + regionB + regionG << " ";
	cout << regionRG + regionB << "\n";

	return 0;
}