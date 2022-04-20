#include <iostream>
#include <queue>
using namespace std;

int height, width;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int plate[100][100] = {};
int visited[100][100] = {};

void input() {
	cin >> height >> width;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> plate[y][x];
		}
	}
}
struct pos {
	int y, x;
};

queue<pos> air;
queue<pos> cheese;

void airSpread() {
	while (!air.empty()) {
		pos now = air.front();
		air.pop();

		for (int i = 0; i < 4; i++) {
			int dy = dr[i] + now.y;
			int dx = dc[i] + now.x;

			if (dy < 0 || dy >= height) continue;
			if (dx < 0 || dx >= width) continue;

			if (visited[dy][dx]) continue;
			
			if (plate[dy][dx]) {
				visited[dy][dx] = visited[now.y][now.x] + 1;
				cheese.push({ dy, dx });
			}
			else {
				visited[dy][dx] = visited[now.y][now.x];
				air.push({ dy, dx });
			}
		}
	}
}

void melting() {
	while (!cheese.empty()) {
		pos now = cheese.front();
		cheese.pop();

		plate[now.y][now.x] = 0;
		air.push(now);

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dr[i];
			int dx = now.x + dc[i];

			if (dy < 0 || dy >= height) continue;
			if (dx < 0 || dx >= width) continue;
			if (!plate[dy][dx]) {
				visited[dy][dx] = visited[now.y][now.x];
				air.push({ dy, dx });
			}
		}
	}
}

int main() {
	input();

	int remain = 0, days = 0;

	air.push({ 0, 0 });
	visited[0][0] = 1;

	while (true) {
		airSpread();
		if (!cheese.empty()) {
			remain = cheese.size();
			days = visited[cheese.front().y][cheese.front().x] - 1;
		}
		melting();
		if (air.empty()) break;
	}

	cout << days << "\n" << remain << "\n";
	return 0;
}