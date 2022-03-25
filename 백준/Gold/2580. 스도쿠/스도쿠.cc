#include <iostream>
using namespace std;

int sudoku[9][9] = {};
bool rowCheck[9][10] = {};
bool colCheck[9][10] = {};
bool boxCheck[9][10] = {};

void printSudoku() {
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << sudoku[y][x] << " ";
		}
		cout << "\n";
	}
}

int getBox(int y, int x) {
	return (y / 3) * 3 + (x / 3);
}

int solve(int n) {
	if (n == 81) {
		printSudoku();
		return 1;
	}
	int x = n % 9, y = n / 9;
	int boxNumber = getBox(y, x);
	if (sudoku[y][x]) return solve(n + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			if (rowCheck[y][i]) continue;
			if (colCheck[x][i]) continue;
			if (boxCheck[boxNumber][i]) continue;
			
			rowCheck[y][i] = true;
			colCheck[x][i] = true;
			boxCheck[boxNumber][i] = true;

			sudoku[y][x] = i;
			if(solve(n + 1)) return 1;
			sudoku[y][x] = 0;

			rowCheck[y][i] = false;
			colCheck[x][i] = false;
			boxCheck[boxNumber][i] = false;
		}
	}
	return 0;
}

void input() {
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> sudoku[y][x];

			int boxNumber = getBox(y, x);
			rowCheck[y][sudoku[y][x]] = true;
			colCheck[x][sudoku[y][x]] = true;
			boxCheck[boxNumber][sudoku[y][x]] = true;
		}
	}
}

int main() {
	input();
	solve(0);
	
	return 0;
}