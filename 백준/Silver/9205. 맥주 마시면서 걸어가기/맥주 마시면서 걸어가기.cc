#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct pos {
	int x, y;
};

pos home, festival;
vector<pos> conv;
vector<int> visited;

int N;

int operator- (pos a, pos b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void input() {
	cin >> N;

	cin >> home.x >> home.y;

	int x, y;
	conv = vector<pos>(0);
	visited = vector<int>(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		conv.push_back({ x, y });
	}

	cin >> festival.x >> festival.y;
}

int walking() {
	queue<pos> q;
	q.push(home);

	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		if (now - festival <= 1000) return 1;
		
		for (int i = 0; i < N; i++) {
			pos to = conv[i];
			if (visited[i]) continue;
			if (now - to > 1000) continue;

			visited[i] = 1;
			q.push(to);
		}
	}
	return 0;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		input();
		if (walking()) cout << "happy\n";
		else cout << "sad\n";
	}
	
	return 0;
}