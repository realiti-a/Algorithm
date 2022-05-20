#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> map(200, vector<char>(0));
int N;

void preTraver(char parent) {
	cout << parent;
	for (int i = 0; i < 2; i++) {
		char children = map[parent][i];
		if (children == '.') continue;
		preTraver(children);
	}
}

void inTraver(char parent) {
	char children = map[parent][0];
	if (children != '.') inTraver(children);
	cout << parent;
	children = map[parent][1];
	if (children != '.') inTraver(children);
}

void postTraver(char parent) {
	for (int i = 0; i < 2; i++) {
		char children = map[parent][i];
		if (children == '.') continue;
		postTraver(children);
	}
	cout << parent;
}

int main() {
	cin >> N;
	char from, to;
	
	for (int i = 0; i < N; i++) {
		cin >> from;
		for (int j = 0; j < 2; j++) {
			cin >> to;
			map[from].push_back(to);
		}
	}

	preTraver('A');
	cout << "\n";
	inTraver('A');
	cout << "\n";
	postTraver('A');
	cout << "\n";
	return 0;
}