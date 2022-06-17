#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> visited;
vector<int> permutation;
void makePer(int level) {
	if (level == N) {
		for (int i = 0; i < N; i++) cout << permutation[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;

		visited[i] = 1;
		permutation.push_back(i);
		makePer(level + 1);
		permutation.pop_back();
		visited[i] = 0;
	}
}

int main() {
	cin >> N;
	visited = vector<int>(N + 1, 0);
	makePer(0);
	return 0;
}