#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char map[25][25];
int visited[25][25] = {};
int N, apartCount;
vector<int> houses;

struct position {
	int y;
	int x;
};
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		cin >> map[y];
	}
}

void bfs(int y, int x) {
	apartCount++;
	queue<position> q;
	q.push({y, x});
	while (!q.empty()) {
		position now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + dc[i];
			int dy = now.y + dr[i];
			if (dx >= N || dx < 0 || dy >= N || dy < 0) continue;
			if (map[dy][dx] == '0') continue;
			if (visited[dy][dx]) continue;
			visited[dy][dx] = 1;
			apartCount++;
			q.push({ dy, dx });
		}
	}
}

void search() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == '0') continue;
			if (visited[y][x]) continue;
			apartCount = 0;
			visited[y][x] = 1;
			bfs(y, x);
			houses.push_back(apartCount);
		}
	}
}

int main() {
	input();
	
	search();
	
	sort(houses.begin(), houses.end());

	cout << houses.size() << "\n";
	for (int i = 0; i < houses.size(); i++) {
		cout << houses[i] << "\n";
	}

	return 0;
}