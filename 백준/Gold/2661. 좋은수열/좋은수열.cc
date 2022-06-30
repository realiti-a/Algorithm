#include <iostream>
#include <string>
using namespace std;

int N;
string s;

bool isOkay() {
	for (int i = 1; i <= s.length() / 2; i++) {
		for (int j = 0; j + 2 * i <= s.length(); j++) {
			string pre = s.substr(j, i);
			string post = s.substr(j + i, i);

			if (pre == post) return false;
		}
	}
	return true;
}

void combination(int level, char pre) {
	if (level == N) {
		cout << s << "\n";
		exit(0);
	}
	for (char next = '1'; next <= '3'; next++) {
		if (pre == next) continue;

		s.push_back(next);
		if (isOkay()) combination(level + 1, next);
		s.pop_back();
	}
}

int main() {
	cin >> N;
	combination(0, '0');
	return 0;
}