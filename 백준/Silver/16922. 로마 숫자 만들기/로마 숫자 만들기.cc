#include <iostream>
#include <set>
using namespace std;

int N;
int numChar[] = { 1, 5, 10, 50 };
set<int> s;

void comb(int level, int res, int before) {
	if (level == N) {
		s.insert(res);
		return;
	}
	for (int i = before; i < 4; i++) comb(level + 1, res + numChar[i], i);
}

int main() {
	cin >> N;
	comb(0, 0, 0);
	cout << s.size() << "\n";
	return 0;
}