#include <iostream>
#include <string>
using namespace std;

int set[21] = {};
int N, number;
string order;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> order;
		if (order == "add") {
			cin >> number;
			set[number]++;
		}
		else if (order == "remove") {
			cin >> number;
			set[number] = 0;
		}
		else if (order == "check") {
			cin >> number;
			cout << (bool)set[number] << "\n";
		}
		else if (order == "toggle") {
			cin >> number;
			if (set[number]) set[number] = 0;
			else set[number]++;
		}
		else if (order == "all") {
			for (int i = 1; i <= 20; i++) {
				set[i] = 1;
			}
		}
		else if (order == "empty") {
			for (int i = 0; i <= 20; i++) {
				set[i] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	return 0;
}