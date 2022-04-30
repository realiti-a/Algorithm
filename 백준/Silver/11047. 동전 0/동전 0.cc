#include <iostream>
using namespace std;

int N, K;
int coin[10] = {}; 

void input(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> coin[i];
    }   
}

int getCoin(){
    int res = 0;
    for(int i = N - 1; i >= 0; i--){
        if(K >= coin[i]){
            res += K / coin[i];
            K %= coin[i];
        }   
        if(!K) break;
    }   
    return res;
}

int main(){
    input();
    cout << getCoin() << "\n";
    return 0;
}