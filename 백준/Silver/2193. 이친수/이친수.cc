#include <iostream>
using namespace std;

long long dp[100] = {}; 

int main(){
    int N; cin >> N;

    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= N; i++){
        long long sum = 0;
        for(int j = 0; j < i - 1; j++) sum += dp[j];
        dp[i] = sum;
    }
    cout << dp[N] << "\n";
    return 0;
}