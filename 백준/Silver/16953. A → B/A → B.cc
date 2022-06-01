#include <iostream>
#include <queue>
using namespace std;

int A, B;

int bfs(long long start){
    queue<long long> q;
    q.push(start);
    int day = 1;

    while(!q.empty()){
        queue<long long> p;
        while(!q.empty()){
            if(q.front() == B) return day;
            p.push(q.front() * 2); 
            p.push(q.front() * 10 + 1); 
            q.pop();
        }   

        int pSize = p.size();
        for(int i = 0; i < pSize; i++){
            if (p.front() <= B){ 
                q.push(p.front());
            }   
            p.pop();
        }   
        day++;
    }   
    return -1; 
}
int main(){
    cin >> A >> B;

    int res = bfs(A);
    
    cout << res << "\n";
    return 0;
}