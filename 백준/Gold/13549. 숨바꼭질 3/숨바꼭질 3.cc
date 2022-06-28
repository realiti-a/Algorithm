#include <iostream>
#include <deque>
#include <vector>
#include <climits>
using namespace std;

vector<int> visited;
int n, k;

void input(){
    cin >> n >> k;
    visited = vector<int> (200000 + 1, INT_MAX);
}

void solve(){
    deque<int> dq; 
    dq.push_back(n);
    visited[n] = 0;

    while(!dq.empty()){
        int now = dq.front();
        dq.pop_front();
        if (now == k){ 
            cout << visited[k] << "\n";
            return;
        }   

        //거리가 0인 경우는 dq 앞에 삽입
        int doubleNext = now * 2;
        if(doubleNext <= 200000 && visited[doubleNext] > visited[now]){
            visited[doubleNext] = visited[now];
            dq.push_front(doubleNext);
        }   

        //거리가 1인 경우는 dq 뒤에 삽입
        for(int i = -1; i <= 1; i += 2){ 
            int next = now + i;
            if(next < 0 || next > 200000) continue;
            if(visited[next] <= visited[now] + 1) continue;
            visited[next] = visited[now] + 1;
            dq.push_back(next);
        }   
    }   
}

int main(){
    input();
    solve();
    return 0;
}