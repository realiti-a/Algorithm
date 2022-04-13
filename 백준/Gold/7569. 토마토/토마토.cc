#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dr[] = {-1, 1, 0, 0, 0, 0};
int dc[] = {0, 0, 1, -1, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};
int row, column, height;

int box[100][100][100] = {};
int visited[100][100][100] = {};

struct position {
	int z, y, x;
};
queue<position> ripeTomatoes;

void input() {
	cin >> column >> row >> height;
	
	for (int z = 0; z < height; z++) {
		for (int y = 0; y < row; y++) {
			for (int x = 0; x < column; x++) {
				cin >> box[z][y][x];
				if (box[z][y][x] == 1) {
					ripeTomatoes.push({ z, y, x });
					visited[z][y][x] = 1;
				}
			}
		}
	}
}

void ripe() {
	while (!ripeTomatoes.empty()) {
		position now = ripeTomatoes.front();
		ripeTomatoes.pop();

		for (int i = 0; i < 6; i++) {
			int dz = now.z + dh[i];
			int dy = now.y + dr[i];
			int dx = now.x + dc[i];

			if (dz < 0 || dz >= height) continue;
			if (dy < 0 || dy >= row) continue;
			if (dx < 0 || dx >= column) continue;

			if (visited[dz][dy][dx]) continue;
			if (box[dz][dy][dx] == -1) continue;

			visited[dz][dy][dx] = visited[now.z][now.y][now.x] + 1;
			box[dz][dy][dx] = 1;
			ripeTomatoes.push({ dz, dy, dx });
		}
	}
}

int getMaxDay() {
	int maxDay = 0;

	int flag = 0;
	for (int z = 0; z < height; z++) {
		for (int y = 0; y < row; y++) {
			for (int x = 0; x < column; x++) {
				if (visited[z][y][x] > maxDay) {
					maxDay = visited[z][y][x];
				}
				else if (!visited[z][y][x] && !box[z][y][x]) {
					flag = 1;
					maxDay = 0;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) break;
	}

	return maxDay - 1;
}

int main() {
	input();
	ripe();
	cout << getMaxDay() << "\n";
	return 0;
}