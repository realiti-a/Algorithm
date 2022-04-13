#include <iostream>
#include <string>
using namespace std;

struct position {
	int y;
	int x;
};

position king, stone;
int N;
string direction = "RLBT";

int dr[] = { 0, 0, -1, 1};
int dc[] = { 1, -1, 0, 0 };

void move(string order, int n) {
	int y = 0, x = 0;
	for (char c : order) {
		y += dr[direction.find(c)];
		x += dc[direction.find(c)];
	}
	position kingNextPos = { king.y + y, king.x + x };
	position stoneNextPos = {0, 0};
	int flag = 0;
	if (kingNextPos.x == stone.x && kingNextPos.y == stone.y) {
		stoneNextPos = { stone.y + y, stone.x + x };
		flag = 1;
	}

	if (kingNextPos.x < 0 || kingNextPos.x > 7) return;
	if (kingNextPos.y < 0 || kingNextPos.y > 7) return;

	if (stoneNextPos.x < 0 || stoneNextPos.x > 7) return;
	if (stoneNextPos.y < 0 || stoneNextPos.y > 7) return;

	king = kingNextPos;
	if (flag) stone = stoneNextPos;
}

void getPos(string position, int n) {
	int y = position[1] - '1';
	int x = position[0] - 'A';

	if (n) {
		stone.y = y;
		stone.x = x;
	}
	else {
		king.y = y;
		king.x = x;
	}
}

void getRes() {
	cout << (char)(king.x + 'A') << (char)(king.y + '1') << "\n";
	cout << (char)(stone.x + 'A') << (char)(stone.y + '1') << "\n";
}

void input() {
	string kingPos, stonePos;

	cin >> kingPos >> stonePos >> N;
	getPos(kingPos, 0);
	getPos(stonePos, 1);

	for (int i = 0; i < N; i++) {
		string order;
		cin >> order;
		move(order, 0);
	}
}


int main() {
	input();
	getRes();
	return 0;
}