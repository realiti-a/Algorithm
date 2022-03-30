#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> sequence;

void input(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        sequence.push(i);
    }
}

void print(){
    cout << "<";
    while(!sequence.empty()){
        for(int i = 0; i < K - 1; i++){
            int number = sequence.front();
            sequence.pop();
            sequence.push(number);
        }
        int number = sequence.front();
        sequence.pop();
        cout << number;
        if(!sequence.empty()) cout << ", ";
    }
    cout << ">\n";
}

int main(){
    input();
    print();
    return 0;
}
