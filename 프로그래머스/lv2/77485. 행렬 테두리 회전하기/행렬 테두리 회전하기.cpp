#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;

void boardFill(int rows, int columns){
    for(int y = 1; y <= rows; y++){
        for(int x = 1; x <= columns; x++){
            board[y][x] = x + (y - 1) * columns;
        }
    }
}

int rotation(vector<int> query){
    int y1 = query[0], x1 = query[1], y2 = query[2], x2 = query[3];
    
    int min = board[y1][x1];
    int tmp = min;
    //좌변
    for(int y = y1; y < y2; y++){
        board[y][x1] = board[y + 1][x1];
        if(board[y][x1] < min) min = board[y][x1];
    }
    //아랫변
    for(int x = x1; x < x2; x++){
        board[y2][x] = board[y2][x + 1];
        if(board[y2][x] < min) min = board[y2][x];
    }
    //우변
    for(int y = y2; y > y1; y--){
        board[y][x2] = board[y - 1][x2];
        if(board[y][x2] < min) min = board[y][x2];
    }
    //윗변
    for(int x = x2; x > x1; x--){
        board[y1][x] = board[y1][x - 1];
        if(board[y1][x] < min) min = board[y1][x];
    }
    board[y1][x1 + 1] = tmp;
    return min;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    board = vector<vector<int>> (rows + 1, vector<int>(columns + 1, 0));
    boardFill(rows, columns);
    
    for(vector<int> query : queries) {
        answer.push_back(rotation(query));
    }
    
    return answer;
}