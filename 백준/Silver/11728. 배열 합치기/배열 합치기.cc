#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
queue<string> A;
queue<string> B;
queue<string> result;

void input(){
    cin >> N >> M;
    string number;
    
    for(int i = 0; i < N; i++){
        cin >> number;
        A.push(number);
    }
    
    for(int i = 0; i < M; i++){
        cin >> number;
        B.push(number);
    }
}

int compare(string a, string b){
    if(a[0] == '-' && b[0] == '-'){
        if(a.length() == b.length()) return a > b;
        return a.length() > b.length();
    }
    else if(a[0] == '-') return 1;
    else if(b[0] == '-') return 0;
    else {
        if(a.length() == b.length()){
        return a < b;
    }
    return a.length() < b.length();
    }
}

void merge(){
    while(!A.empty() && !B.empty()){
        string a = A.front();
        string b = B.front();
        if(compare(a, b)){
            result.push(a);
            A.pop();
        }
        else {
            result.push(b);
            B.pop();
        }
    }
    
    while(!A.empty()){
        string a = A.front();
        A.pop();
        result.push(a);
    }
    
    while(!B.empty()){
        string b = B.front();
        B.pop();
        result.push(b);
    }
}

void printing(){
    while(!result.empty()){
        string res = result.front();
        cout << res << " ";
        result.pop();
    }
    cout << "\n";
}

int main(){
    input();
    merge();
    printing();
    return 0;
}
