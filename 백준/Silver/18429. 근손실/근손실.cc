#include <iostream>
using namespace std;

int N, K, cnt, HP; 
int kit[10];
int used[10] = {}; 

void input(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> kit[i];
    }   
    cnt = 0;
    HP = 500;
}

void workout(int level){
    if(HP < 500) return;
    if(level == N){ 
        cnt++;
        return;
    }   

    for(int i = 0; i < N; i++){
        if(used[i]) continue;
            
        used[i] = 1;
        HP += kit[i] - K;
        workout(level + 1); 
        HP -= kit[i] - K;
        used[i] = 0;
    }   
}

int main(){
    input();
    workout(0);
    cout << cnt << "\n";
    return 0;
}