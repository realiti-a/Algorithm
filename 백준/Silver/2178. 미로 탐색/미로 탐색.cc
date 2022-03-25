#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int y;
	int x;
};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int N, M;
char map[100][101];
int visited[100][100] = {};

queue<Point> q;

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		cin >> map[y];
	}
}

int main() {
	input();

	visited[0][0] = 1;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + dr[i];
			int dx = x + dc[i];

			if (dy < 0 || dy >= N) continue;
			if (dx < 0 || dx >= M) continue;

			if (visited[dy][dx]) continue;
			if (map[dy][dx] == '0') continue;

			q.push({ dy, dx });
			visited[dy][dx] = visited[y][x] + 1;
			if (dy == N - 1 && dx == M - 1) break;
		}
	}

	cout << visited[N - 1][M - 1] << "\n";

	return 0;
}