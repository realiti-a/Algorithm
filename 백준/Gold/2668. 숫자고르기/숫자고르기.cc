#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;
vector<int> table;
vector<int> visited;
set<int> s;

void input() {
	cin >> N;
	table = vector<int>(N + 1, 0);
	
	for (int i = 1; i <= N; i++) {
		cin >> table[i];
	}
}

void dfs(int now) {
	visited[now] = 1;
	int to = table[now];

	if (visited[to]) {
		s.insert(to);
		return;
	}
	else {
		dfs(to);
	}
}
int main() {
	input();
	for (int i = 1; i <= N; i++) {
		if (s.find(i) != s.end()) continue;
		
		visited = vector<int>(N + 1, 0);
		dfs(i);
	}

	cout << s.size() << "\n";
	for (int i : s) {
		cout << i << "\n";
	}
	return 0;
}