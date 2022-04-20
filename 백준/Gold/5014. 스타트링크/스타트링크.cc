#include <iostream>
#include <queue>
using namespace std;

int floors, startLink, gangho;
int updown[2] = {};
int dr[] = { 1, -1 };
int building[1000001] = {};
queue<int> q;

void input() {
	cin >> floors >> gangho >> startLink >> updown[0] >> updown[1];
}

int elevator() {
	q.push(gangho);
	building[gangho] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		if (now == startLink) return building[now] - 1;

		for (int i = 0; i < 2; i++) {
			int next = now + dr[i] * updown[i];

			if (next > floors || next <= 0) continue; 
			if (building[next]) continue;

			building[next] = building[now] + 1;
			q.push(next);
		}
	}
	return -1;
}

int main() {
	input();
	int res = elevator();

	if (res == -1) cout << "use the stairs\n";
	else cout << res << "\n";
	return 0;
}