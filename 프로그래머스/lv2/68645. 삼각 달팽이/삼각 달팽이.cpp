#include <string>
#include <vector>
using namespace std;

vector<vector<int>> triangle;

void drawTriangle(int y, int x, int n, int number) {
    if (n <= 0) return;
    for (int i = y; i < y + n; i++) {
        triangle[i][x] = number++;
    }
    for (int j = x + 1; j < x + n; j++) {
        triangle[y + n - 1][j] = number++;
    }
    for(int i = 0; i < n - 2; i++){
        int dy = y + n - 2 - i;
        int dx = x + n - 2 - i;
        
        triangle[dy][dx] = number++;
    }

    drawTriangle(y + 2, x + 1, n - 3, number);
}

vector<int> solution(int n) {
    vector<int> answer;
    triangle = vector<vector<int>>(n, vector<int>(n, 0));

    drawTriangle(0, 0, n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(triangle[i][j]);
        }
    }

    return answer;
}