#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> visited;
string num;
char path[10] = {};
int cnt = 0;
set<int> s;

int isPrime(int num){
    if(num < 2) return 0;
    for(int i = 2; i < num; i++){
        if(num % i == 0) return 0;
    }
    return 1;
}

int atoi(char *c){
    int result = 0;
    for(int i = 0; i < 10; i++){
        if(c[i] == 0) break;
        
        result = result * 10 + (c[i] - '0');
    }
    return result;
}

void run(int level){
    int n = atoi(path);
    if(isPrime(n) && s.find(n) == s.end()){
        s.insert(n);
        cnt++;
    }
    if(level == num.length()) return;
    
    for(int i = 0; i < num.length(); i++){
        if(visited[i]) continue;
        
        visited[i] = 1;
        path[level] = num[i];
        
        run(level + 1);
        
        path[level] = 0;
        visited[i] = 0;
    }
}


int solution(string numbers) {
    visited = vector<int>(numbers.length(), 0);
    num = numbers;
    
    run(0);
    
    return cnt;
}