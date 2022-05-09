#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//100개의 칸으로 나누어져 있는 보드판
//도착한 칸이 사다리면, 사다리 타고 위로 올라간다. 뱀이 있는 칸에 도착하면, 뱀을 따라 내려가게 된다.
//사다리를 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 크고, 뱀을 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 작아짐.

vector<int> ladders(101, 0);
vector<int> visited(101, 0);
int N, M;//사다리의 수 N, 뱀의 수 M
void input() {
	cin >> N >> M;

	int from, to;
	for (int i = 0; i < N + M; i++) {
		cin >> from >> to;

		ladders[from] = to;
	}
}

void playGame() {
	queue<int> q;
	q.push(1);
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int to = now + i;
			//보드판 벗어나는 예외
			if (to <= 0 || to > 100) continue;
			//사다리 타고 이동
			if (ladders[to]) to = ladders[to];
			//이미 갔던 값은 피하기
			if (visited[to]) continue;

			visited[to] = visited[now] + 1;
			q.push(to);
		}
	}
}

int main() {
	input();
	playGame();
	cout << visited[100] << "\n";

	return 0;
}