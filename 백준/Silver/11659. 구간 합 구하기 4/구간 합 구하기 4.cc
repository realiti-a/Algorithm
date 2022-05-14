#include <iostream>
using namespace std;

int accSum[100001] = {}; 

int N, M;
void input(){
    cin >> N >> M;

    int num, sum = 0;
    for(int i = 1; i <= N; i++){
        cin >> num;

        sum += num;
        accSum[i] = sum;
    }   
}   

void output(){
    int from, to; 
    for(int i = 0; i < M; i++){
        cin >> from >> to; 
    
        int result = accSum[to] - accSum[from - 1]; 
        cout << result << "\n";
    }   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    output();
    return 0;
}