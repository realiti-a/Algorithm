#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int dr[] = {-1, -1, 0};
    int dc[] = {-1, 0, -1};
    int maxWidth = 0;
    
    if(board.size() == 1) {
        for(int i = 0; i < board[0].size(); i++){
            if(board[0][i]) return 1;
        }
        return 0;
    }
    
    for(int y = 1; y < board.size(); y++){
        for(int x = 1; x < board[y].size(); x++){
            int min = 1000;
            if(!board[y][x]) continue;
            
            for(int i = 0; i < 3; i++){
                int dy = y + dr[i];
                int dx = x + dc[i];
                
                if(min > board[dy][dx]){
                    min = board[dy][dx];
                }
            }
            
            board[y][x] = min + 1;
            if(board[y][x] > maxWidth) maxWidth = board[y][x];
        }
    }
    
    return maxWidth * maxWidth;
}