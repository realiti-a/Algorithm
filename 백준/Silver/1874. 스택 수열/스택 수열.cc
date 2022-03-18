#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
string path;
stack<int> series;
int flag = 0, Max = 0;

int makeSeries(int number) {
	for (int i = Max + 1; i <= number; i++) {
		series.push(i);
		path += "+";
	}
	if (number > Max) Max = number;

	if (series.top() == number) {
		series.pop();
		path += "-";
		return 1;
	}
	else return 0;
}

void input() {
	cin >> n;
	int number;
	series.push(0);
	for (int i = 0; i < n; i++) {
		cin >> number;
		if (!makeSeries(number)) {
			flag = 1;
			break;
		}
	}
}

int main() {
	input();
	if (flag) cout << "NO\n" << "\n";
	else {
		for (int i = 0; i < path.length(); i++) {
			cout << path[i] << "\n";
		}
	}
	return 0;
}