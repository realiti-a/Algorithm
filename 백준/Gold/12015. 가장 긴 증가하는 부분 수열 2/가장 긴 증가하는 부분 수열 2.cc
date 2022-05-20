#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sequence;
vector<int> length;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	sequence = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> sequence[i];

		if (length.size() == 0) length.push_back(sequence[i]);
		else if (length[length.size() - 1] < sequence[i]) length.push_back(sequence[i]);
		else {
			int index = lower_bound(length.begin(), length.end(), sequence[i]) - length.begin();
			length[index] = sequence[i];
		}
	}

	cout << length.size() << "\n";
	return 0;
}