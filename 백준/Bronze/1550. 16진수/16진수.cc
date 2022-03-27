#include <iostream>
using namespace std;

char hexNumber[7];

int main() {
	cin >> hexNumber;

	int answer = 0;
	for (int i = 0; i < 7; i++) {
		if (hexNumber[i] == '\0') break;
		else if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
			answer = answer * 16 + (hexNumber[i] - '0');
		}
		else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'Z') {
			answer = answer * 16 + (hexNumber[i] - 'A' + 10);
		}
	}

	cout << answer << "\n";
	return 0;
}