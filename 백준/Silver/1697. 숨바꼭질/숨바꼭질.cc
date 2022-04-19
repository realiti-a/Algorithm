#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visited[100001] = {}; 
int day = 0;
queue<int> q;

void input(){
    cin >> N >> K;
}

void search(){
    q.push(N);
    visited[N] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i = 0; i < 3; i++){
            int to = now;
            if(i == 0) to -= 1;
            else if(i == 1) to += 1;
            else if(i == 2) to *= 2;

            if(to < 0 || to > 100000) continue; 
            if(visited[to]) continue;
    
            visited[to] = visited[now] + 1;
            if(to == K) {
                day = visited[now];
                return;
            }   

            q.push(to); 
        }   
    }   
}
int main(){
    input();
    search();
    cout << day << "\n";
    return 0;
}