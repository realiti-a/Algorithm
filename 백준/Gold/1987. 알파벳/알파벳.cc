#include <iostream>
#include <string>
#include <vector>
using namespace std;

int R, C;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
vector<string> map;
vector<int> visited;

int dfs(int y, int x, int now) {
	int maxNow = now;
	for (int i = 0; i < 4; i++) {
		int dy = y + dr[i];
		int dx = x + dc[i];

		if (dy < 0 || dy >= R) continue;
		if (dx < 0 || dx >= C) continue;
		char to = map[dy][dx];
		if (visited[to]) continue;

		visited[to] = 1;
		int nextNow = dfs(dy, dx, now + 1);
		visited[to] = 0;
		if (nextNow > maxNow) maxNow = nextNow;
	}
	return maxNow;
}

int main() {
	cin >> R >> C;

	map = vector<string>(R, "");
	visited = vector<int>(200, 0);

	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}

	visited[map[0][0]] = 1;
	cout << dfs(0, 0, 1) << "\n";;

	return 0;
}