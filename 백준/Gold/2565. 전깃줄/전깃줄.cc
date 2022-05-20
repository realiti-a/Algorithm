#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sequence[501] = {};
vector<int> length;

int main() {
	int N; cin >> N;

	int from, to;
	for (int i = 0; i < N; i++) {
		cin >> from >> to;
		sequence[from] = to;
	}

	for (int i = 1; i <= 500; i++) {
		if (!sequence[i]) continue;
		if (length.size() == 0) length.push_back(sequence[i]);
		else if (length[length.size() - 1] < sequence[i]) length.push_back(sequence[i]);
		else {
			int index = lower_bound(length.begin(), length.end(), sequence[i]) - length.begin();
			length[index] = sequence[i];
		}
	}

	cout << N - length.size() << "\n";
	return 0;
}