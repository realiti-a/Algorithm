#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> visited;
vector<int> path;
int maxValue = 0;

int getSum() {
	int res = 0;
	for (int i = 0; i < path.size() - 1; i++) {
		res += abs(path[i] - path[i + 1]);
	}
	return res;
}

void combi(int level) {
	if (level == arr.size()) {
		int sum = getSum();
		if (sum > maxValue) maxValue = sum;
		return;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (visited[i]) continue;

		visited[i] = 1;
		path.push_back(arr[i]);
		combi(level + 1);
		path.pop_back();
		visited[i] = 0;
	}
}
int main() {
	int N; cin >> N;
	arr = vector<int>(N, 0);
	visited = vector<int>(N, 0);
	for (int i = 0; i < N; i++) cin >> arr[i];

	combi(0);
	cout << maxValue << "\n";
	return 0;
}