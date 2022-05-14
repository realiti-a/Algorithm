#include <iostream>
#include <vector>
using namespace std;

vector<long long> interval;

long long comb(long long N){ 
    return N*(N - 1) / 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M;
    cin >> N >> M;

    interval = vector<long long>(M, 0); 

    long long sum = 0;
    long long num;

    for(int i = 0; i < N; i++){
        cin >> num;

        sum += num;
        sum %= M;
        interval[sum]++;
    }   

    interval[0]++;
    long long result = 0;
    for(int i = 0; i < M; i++){
        result += comb(interval[i]);
    }   
    cout << result << "\n";

    return 0;
}