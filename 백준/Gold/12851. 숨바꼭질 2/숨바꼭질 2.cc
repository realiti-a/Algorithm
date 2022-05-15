#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dr[3] = { -1, 1, 0 };
int visited[100001] = {};

void bfs() {
	queue<int> q;
	q.push(N);

	int day = 0, cnt = 0;
	while (!cnt) {
		//q에 있는 거 다 뽑아서 이동한 위치 다시 q에 다 담아(bfs)
		int qSize = q.size();

		for (int i = 0; i < qSize; i++) {
			int now = q.front();
			dr[2] = now;
			visited[now] = 1;
			q.pop();
			if (now == K) cnt++;
			for (int j = 0; j < 3; j++) {
				int to = now + dr[j];
				if (to < 0 || to > 100000) continue;
				if (visited[to]) continue;
				q.push(to);
			}
		}
		//날짜 up
		day++;
	}
	cout << day - 1 << "\n";
	cout << cnt << "\n";
}

int main() {
	cin >> N >> K;
	bfs();
	return 0;
}