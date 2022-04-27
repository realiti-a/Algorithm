#include <iostream>
using namespace std;

int N, M;
int board[500][500] = {};
int visited[500][500] = {};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}
}

int Max = 0;
void tetro(int y, int x, int sum, int level) {
	if (level == 3) {
		if (sum > Max) Max = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int dy = y + dr[i];
		int dx = x + dc[i];

		if (dy < 0 || dy >= N) continue;
		if (dx < 0 || dx >= M) continue;

		if (visited[dy][dx]) continue;

		visited[dy][dx] = 1;
		tetro(dy, dx, sum + board[dy][dx], level + 1);
		visited[dy][dx] = 0;
	}
	return;
}

void purple(int y, int x) {
	int res;
	for (int i = 0; i < 4; i++) {
		res = board[y][x];
		int flag = 0;
		for (int j = 0; j < 3; j++) {
			int dy = y + dr[(i + j) % 4];
			int dx = x + dc[(i + j) % 4];

			if (dy < 0 || dy >= N) {
				flag = 1;
				break;
			}
			if (dx < 0 || dx >= M) {
				flag = 1;
				break;
			}

			res += board[dy][dx];
		}
		if (flag) continue;
		if (res > Max) Max = res;
	}
	return;
}
int main() {
	//입력
	input();
	//보라색 조각 빼고 탐색
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			visited[y][x] = 1;
			tetro(y, x, board[y][x], 0);
			visited[y][x] = 0;
		}
	}
	//보라색 조각 탐색
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			purple(y, x);
		}
	}
	//결과 출력
	cout << Max << "\n";
	return 0;
}