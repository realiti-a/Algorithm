#include <iostream>
using namespace std;

int sequence[1000] = {};
int length[1000] = {};

int main() {
	int N;
	cin >> N;

	int maxLength = 0;
	for (int i = 0; i < N; i++) {
		cin >> sequence[i];
		
		length[i] = 1;
		for (int j = 0; j < i; j++) {
			if (sequence[j] < sequence[i] && length[j] >= length[i]) {
				length[i] = length[j] + 1;
			}
		}
		if (length[i] > maxLength) maxLength = length[i];
	}

	cout << maxLength << "\n";
	return 0;
}