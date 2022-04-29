#include <iostream>
using namespace std;

int N;
int cnt[2] = {}; 
int paper[128][128] = {}; 

void input(){
    cin >> N;
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            cin >> paper[y][x];
        }   
    }   
}

int isSameColor(int dy, int dx, int size){
    int color = paper[dy][dx];
    
    for(int y = dy; y < dy + size; y++){
        for(int x = dx; x < dx + size; x++){
            if(paper[y][x] != color) return 0;
        }   
    }   
    return 1;
}

void cut(int y, int x, int size){
    if(size == 1){ 
        cnt[paper[y][x]]++;
        return;
    }   

    if(isSameColor(y, x, size)){
        cnt[paper[y][x]]++;
        return;
    }   
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            int dy = y + i * size / 2;
            int dx = x + j * size / 2;
            cut(dy, dx, size / 2); 
        }   
    }   
}

int main(){
    input();

    cut(0, 0, N); 

    for(int i : cnt) cout << i << "\n";
    return 0;
}