#include <iostream>
#include <set>
using namespace std;

set<int> A;
int AN, BN, bothCount;
void input() {
	cin >> AN >> BN;

	int number;
	for (int i = 0; i < AN; i++) {
		cin >> number;
		
		A.insert(number);
	}

	bothCount = 0;
	for (int i = 0; i < BN; i++) {
		cin >> number;

		if (A.find(number) != A.end()) bothCount++;
	}
}

int main() {
	input();

	int symmetric = AN + BN - bothCount * 2;

	cout << symmetric << "\n";
	return 0;
}