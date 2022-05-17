#include <iostream>
using namespace std;

int board[1001][1001] = {}; 

int main(){
    int N, K;
    cin >> N >> K;

    for(int y = 0; y <= N; y++){
        for(int x = 0; x <= y; x++){
            if(x == 0 || x == y) {
                board[y][x] = 1;
                continue;
            }   
            board[y][x] = (board[y - 1][x] + board[y - 1][x - 1])%10007;
        }   
    }   

    cout << board[N][K] << "\n";
    return 0;
}