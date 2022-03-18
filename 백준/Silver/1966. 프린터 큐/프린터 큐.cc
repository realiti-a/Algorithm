#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct document {
	int importance;
	int order;
};

queue<document> printer;
vector<int> importances;
int N, order, cnt;

void input() {
	cnt = 0;
	printer = queue<document>();
	importances = vector<int>(10, 0);
	
	cin >> N >> order;

	int importance;
	for (int i = 0; i < N; i++) {
		cin >> importance;
		printer.push({ importance, i });
		importances[importance]++;
	}
}

int getMax() {
	int res;
	for (int i = 9; i >= 0; i--) {
		if (importances[i]) {
			res = i;
			break;
		}
	}
	return res;
}

void printing() {
	while (!printer.empty()) {
		cnt++;
		document doc = printer.front();
		printer.pop();
		if (doc.importance == getMax()) {
			importances[doc.importance]--;
			if (doc.order == order) break;
		}
		else {
			printer.push(doc);
			cnt--;
		}
	}
	return;
}


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		input();
		printing();
		cout << cnt << "\n";
	}
	return 0;
}