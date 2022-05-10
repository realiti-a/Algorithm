#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
vector<vector<vector<int>>> visited;

struct pos {
	int z, y, x;
};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int N, M;
void input() {
	cin >> N >> M;
	string str;

	map = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<vector<int>>>(2, vector<vector<int>>(N, vector<int>(M, 0)));

	for (int y = 0; y < N; y++) {
		cin >> str;

		for (int x = 0; x < M; x++) {
			map[y][x] = str[x] - '0';
		}
	}
}

void bfs() {
	queue<pos> q;
	q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dr[i];
			int dx = now.x + dc[i];

			if (dy < 0 || dy >= N) continue;
			if (dx < 0 || dx >= M) continue;

			if (now.z) {
				// 이전에 이미 벽을 부수고 지나온 경우
				// 이제 벽을 더 이상 부술 수 없어서 벽을 부수고 지나갈 수 없음
				if (map[dy][dx]) continue;
				if (visited[1][dy][dx]) continue;

				visited[1][dy][dx] = visited[1][now.y][now.x] + 1;
				q.push({ 1, dy, dx });
			}
			else {
				// 이전에 벽을 부수지 않고 지나온 경우
				// 벽이 있으면 일단 부숴봄
				if (map[dy][dx]) {
					if (visited[1][dy][dx]) continue;

					visited[1][dy][dx] = visited[0][now.y][now.x] + 1;
					q.push({ 1, dy, dx });
				}
				else {
					if (visited[0][dy][dx]) continue;
					
					visited[0][dy][dx] = visited[0][now.y][now.x] + 1;
					q.push({ 0, dy, dx });
				}
			}
		}
	}
}

int getRes() {
	int breakWall = visited[1][N - 1][M - 1];
	int noBreak = visited[0][N - 1][M - 1];

	if (!breakWall && !noBreak) return -1;
	else if (noBreak && breakWall) return noBreak < breakWall ? noBreak : breakWall;
	else if (noBreak) return noBreak;
	else if (breakWall) return breakWall;
}
int main() {
	input();
	bfs();
	cout << getRes() << "\n";
	return 0;
}