#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int N, M;
string name;
set<string> cantSee;
set<string> both;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> name;
		cantSee.insert(name);
	}
	for (int j = 0; j < M; j++) {
		cin >> name;
		if (cantSee.find(name) == cantSee.end()) continue;
		both.insert(name);
	}
	
	cout << both.size() << "\n";
	set<string>::iterator iter;
	for (iter = both.begin(); iter != both.end(); iter++) {
		cout << *iter << "\n";
	}

	return 0;
}