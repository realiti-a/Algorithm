#include <iostream>
#include <vector>
using namespace std;

struct pos {
    int y, x;
};

int N, M;
vector<vector<int>> map;
vector<pos> secureCam;
int dr[] = {-1, 0, 1, 0}; 
int dc[] = {0, -1, 0, 1}; 
int minSize = 100;

void input(){
    cin >> N >> M;
    map = vector<vector<int>>(N, vector<int>(M, 0));
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            cin >> map[y][x];
            if(map[y][x] > 0 && map[y][x] < 6) secureCam.push_back({y, x});
        }   
    }   
}

void draw(int dir, int y, int x, int fill){
    while(true){
        y += dr[dir];
        x += dc[dir];
        if(x < 0 || x >= M) return;
        if(y < 0 || y >= N) return;
        if(map[y][x] == 6) return;
        if(map[y][x] > 0 && map[y][x] < 6) continue;
        if(fill == 100) fill = 9;
        else if(fill == 0) fill = -9; 
        map[y][x] += fill;
    }   
}

int getBlindSpot(){
    int area = 0;
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++){
            if(!map[y][x]) area++; 
        }   
    }   
    return area;
}

void setCamera(int level){
    if(level == secureCam.size()){
        int blindSize = getBlindSpot();
        if(minSize > blindSize) minSize = blindSize;
        return;
    }   
    pos now = secureCam[level];
    int num = map[now.y][now.x];

    if(num == 1){ 
        for(int i = 0; i < 4; i++){
            draw(i, now.y, now.x, 100);
            setCamera(level + 1);
            draw(i, now.y, now.x, 0);
        }
    }
    else if(num == 2){
        for(int i = 0; i < 2; i++){
            draw(i, now.y, now.x, 100);
            draw(i + 2, now.y, now.x, 100);
            setCamera(level + 1);
            draw(i, now.y, now.x, 0);
            draw(i + 2, now.y, now.x, 0);
        }
    }
    else if(num == 3){
        for(int i = 0; i < 4; i++){
            draw(i, now.y, now.x, 100);
            draw((i + 1) % 4, now.y, now.x, 100);
            setCamera(level + 1);
            draw(i, now.y, now.x, 0);
            draw((i + 1) % 4, now.y, now.x, 0);
        }
    }
    else if(num == 4){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                draw((i + j) % 4, now.y, now.x, 100);
            }
            setCamera(level + 1);
            for(int j = 0; j < 3; j++){
                draw((i + j) % 4, now.y, now.x, 0);
            }
        }
    }
    else if(num == 5){
        for(int i = 0; i < 4; i++) draw(i, now.y, now.x, 100);
        setCamera(level + 1);
        for(int i = 0; i < 4; i++) draw(i, now.y, now.x, 0);
    }
}

int main(){
    input();
    setCamera(0);
    cout << minSize << "\n";
    return 0;
}
