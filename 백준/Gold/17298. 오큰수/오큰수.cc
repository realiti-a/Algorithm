#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
stack<int> index;
int result[1000000] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;

		if (s.empty()) {
			s.push(input);
			index.push(i);
		}
		else {
			while (s.top() < input) {
				result[index.top()] = input;
				index.pop();
				s.pop();

				if (s.empty()) break;
			}
			s.push(input);
			index.push(i);
		}
	}

	while (!index.empty()) {
		result[index.top()] = -1;
		index.pop();
	}

	for (int i = 0; i < N; i++) cout << result[i] << " ";

	return 0;
}