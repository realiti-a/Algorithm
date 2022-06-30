#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <cstdio>
#include <climits>
using namespace std;

struct pos {
	int y, x;
};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

vector<vector<char>> map;
vector<vector<vector<int>>> visited;
vector<pos> prisoners;
int h, w;

void input() {
	cin >> h >> w;
	map = vector<vector<char>>(h + 2, vector<char>(w + 2, 0));
	visited = vector<vector<vector<int>>>(3, vector<vector<int>>(h + 2, vector<int>(w + 2, INT_MAX)));
	prisoners = vector<pos>(1, { 0, 0 });
	for (int y = 1; y <= h; y++) {
		for (int x = 1; x <= w; x++) {
			map[y][x] = getchar();
			if (map[y][x] == '\n') map[y][x] = getchar();
			if (map[y][x] == '$') {
				prisoners.push_back({ y, x });
			}
		}
	}
}

void solve(int order) {
	pos prisoner = prisoners[order];
	deque<pos> dq;
	dq.push_back(prisoner);
	visited[order][prisoner.y][prisoner.x] = 0;

	while (!dq.empty()) {
		pos now = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dr[i];
			int dx = now.x + dc[i];

			if (dy < 0 || dy >= h + 2) continue;
			if (dx < 0 || dx >= w + 2) continue;

			//벽
			if (map[dy][dx] == '*') continue;
			//문
			else if (map[dy][dx] == '#') {
				if (visited[order][dy][dx] <= visited[order][now.y][now.x] + 1) continue;
				visited[order][dy][dx] = visited[order][now.y][now.x] + 1;
				dq.push_back({ dy, dx });
			}
			//다른 거
			else {
				if (visited[order][dy][dx] <= visited[order][now.y][now.x]) continue;
				visited[order][dy][dx] = visited[order][now.y][now.x];
				dq.push_front({ dy, dx });
			}
		}
	}
}

int getMin() {
	int minValue = INT_MAX;
	for (int y = 0; y < h + 2; y++) {
		for (int x = 0; x < w + 2; x++) {
			int sum = 0;
			for (int i = 0; i < 3; i++) sum += visited[i][y][x];
			if (map[y][x] == '#') sum -= 2;
			if (sum < minValue) minValue = sum;
		}
	}
	return minValue;
}

int main() {
	int t; cin >> t;
	for (int j = 0; j < t; j++) {
		input();
		for (int i = 0; i < 3; i++) solve(i);
		cout << getMin() << "\n";;
	}
	return 0;
}