#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int N;
map<string, vector<string>> m;
void input() {
	cin >> N;
	
	m.clear();
	string clothes, type;
	for (int i = 0; i < N; i++) {
		cin >> clothes >> type;

		if (m.find(type) == m.end()) {
			m[type] = vector<string>(1, clothes);
		}
		else {
			m[type].push_back(clothes);
		}
	}
}

int getRes() {
	int result = 1;
	for (auto v : m) {
		result *= v.second.size() + 1;
	}
	return result - 1;
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		input();
		cout << getRes() << "\n";
	}
	return 0;
}