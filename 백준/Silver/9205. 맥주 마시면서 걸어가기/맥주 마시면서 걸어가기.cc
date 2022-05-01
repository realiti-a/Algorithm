#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct pos {
	int y, x;
};

int operator- (pos a, pos b) {
	return abs(a.y - b.y) + abs(a.x - b.x);
}

vector<pos> convenience;
vector<int> visited;

int N;
pos home, festival;

void input() {
	cin >> N;

	convenience = vector<pos>(N, {0, 0});
	visited = vector<int>(N, 0);
	int y, x;
	cin >> home.x >> home.y;

	for (int i = 0; i < N; i++) {
		cin >> convenience[i].x >> convenience[i].y;
	}

	cin >> festival.x >> festival.y;
}

int letgo() {
	queue<pos> q;
	q.push(home);

	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		if (festival - now <= 1000) return 1;

		for (int i = 0; i < N; i++) {
			pos to = convenience[i];

			if (visited[i]) continue;
			if (now - to > 1000) continue;

			visited[i] = 1;
			q.push(convenience[i]);
		}
	}
	return 0;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		input();
		if (letgo()) cout << "happy\n";
		else cout << "sad\n";
	}
	return 0;
}