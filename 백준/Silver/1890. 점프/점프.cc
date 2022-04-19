#include <iostream>
using namespace std;

int N;
int map[100][100] = {}; 
long long record[100][100] =  {}; 

void input(){
    cin >> N;
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            cin >> map[y][x];
        }   
    }   
    record[0][0] = 1;
}

void search(){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            if(!record[y][x]) continue;
            if(x == N - 1 && y == N - 1) continue;

            int nextY = map[y][x] + y;
            int nextX = map[y][x] + x;

            if(nextY < N) record[nextY][x] += record[y][x];
            if(nextX < N) record[y][nextX] += record[y][x];
        }   
    }   
}


int main(){
    input();    
    search();
    cout << record[N - 1][N - 1] << "\n";
    return 0;
}