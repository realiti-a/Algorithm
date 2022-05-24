#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edges;
vector<int> parents;
int N;

void dfs(int parent) {
	for (int i = 0; i < edges[parent].size(); i++) {
		int to = edges[parent][i];
		if (parents[to]) continue;

		parents[to] = parent;
		dfs(to);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	edges = vector<vector<int>>(N + 1, vector<int>(0));
	parents = vector<int>(N + 1, 0);

	int from, to;
	for (int i = 0; i < N - 1; i++) {
		cin >> from >> to;

		edges[from].push_back(to);
		edges[to].push_back(from);
	}

	parents[1] = 1;
	dfs(1);

	for (int i = 2; i <= N; i++) cout << parents[i] << "\n";
	return 0;
}