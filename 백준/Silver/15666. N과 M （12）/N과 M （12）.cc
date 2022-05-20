#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10] = {};
int path[10] = {};

void run(int level, int start) {
	if (level == M) {
		for (int i = 0; i < M; i++) cout << path[i] << " ";
		cout << "\n";
		return;
	}
	int before = 0;
	for (int i = start; i < N; i++) {
		int now = arr[i];
		if (before == now) continue;
		before = now;
		path[level] = now;
		run(level + 1, i);
		path[level] = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	run(0, 0);
	return 0;
}