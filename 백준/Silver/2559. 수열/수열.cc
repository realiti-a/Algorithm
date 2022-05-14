#include <iostream>
using namespace std;

int N, K;
int temp[100000] = {}; 

void input(){
    cin >> N >> K;

    int sum = 0;
    for(int i = 0; i < K; i++){
        cin >> temp[i];
        sum += temp[i];
    }   

    int maxValue = sum;

    for(int i = K; i < N; i++){
        cin >> temp[i];

        sum += temp[i] - temp[i - K]; 
        if(sum > maxValue) maxValue = sum;
    }   
    cout << maxValue << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}