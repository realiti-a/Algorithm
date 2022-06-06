#include <iostream>
using namespace std;

int cards[1001] = {}; 
int dp[1001] = {}; 

int main(){
    int N; cin >> N;
    
    for(int i = 1; i <= N; i++) cin >> cards[i];

    for(int i = 1; i <= N; i++){
        int maxPay = 0;
        for(int j = 0; j <= N; j++){
            int nextPay = dp[j] + cards[i - j]; 
            if(nextPay > maxPay) maxPay = nextPay;
        }   
        dp[i] = maxPay;
    }   
    cout << dp[N] << "\n";
    return 0;
}