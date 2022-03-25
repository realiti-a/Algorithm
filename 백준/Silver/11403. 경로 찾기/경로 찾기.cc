#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<int>> visited;

void input() {
	cin >> N;

	map = vector<vector<int>>(N, vector<int>(N, 0));
	visited = vector<vector<int>>(N, vector<int>(N, 0));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
}

void search(int start, int now) {
	for (int to = 0; to < N; to++) {
		if (visited[start][to]) continue;
		if (!map[now][to]) continue;
		
		visited[start][to] = 1;
		search(start, to);
	}
}

void print() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << visited[y][x] << " ";
		}
		cout << "\n";
	}
}

int main() {
	input();

	for (int i = 0; i < N; i++) {
		search(i, i);
	}

	print();
	return 0;
}