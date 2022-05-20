#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int sequence[10] = {};
int visited[10] = {};
int path[10] = {};

void run(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++) cout << path[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;

		visited[i] = 1;
		path[level] = sequence[i];
		run(level + 1);
		path[level] = 0;
		visited[i] = 0;
	}
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> sequence[i];
	sort(sequence, sequence + N);
	run(0);

	return 0;
}