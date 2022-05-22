#include <iostream>
using namespace std;

int dp[1001] = {}; 

int main(){
    int N;
    cin >> N;
    
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= N; i++){
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }   
    cout << dp[N] << "\n";
    return 0;
}
