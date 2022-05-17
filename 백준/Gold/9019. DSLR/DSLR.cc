#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<string> visited;
int A, B;
string order = "DSLR";

string make4(string a){ 
    while(a.length() != 4){ 
        a = "0" + a;
    }   
    return a;
}

int D(int n){ 
    n *= 2;
    if(n > 9999) return n % 10000;
    return n;
}

int S(int n){ 
    n -= 1;
    if(n < 0) return 10000 + n;
    return n;
}

int L(int n){ 
    int res = n % 1000 * 10 + n / 1000;
    return res;
}

int R(int n){ 
    int res = n / 10 + n % 10 * 1000;
    return res;
}

int (*fp[4])(int) = {D, S, L, R}; 

void input(){
    cin >> A >> B;
    visited = vector<string> (10000, "");
}

void bfs(){
    queue<int> q;
    q.push(A);
    visited[A] = ".";
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
    
        if(now == B) break;
        for(int i = 0; i < 4; i++){
            int to = fp[i](now);

            if(visited[to] != "") continue;
            visited[to] = visited[now] +  order[i];
            q.push(to);
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        input();
        bfs();
        cout << visited[B].substr(1) << "\n";
    }
    return 0;
}