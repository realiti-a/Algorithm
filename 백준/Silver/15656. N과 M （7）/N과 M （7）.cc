#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int arr[10] = {};
int visited[10] = {};
int path[10] = {};
int N, M;

set<vector<int>> s;

void run(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++) cout << path[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		int now = arr[i];

		path[level] = now;
		run(level + 1);
		path[level] = 0;
	}
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	run(0);
	return 0;
}