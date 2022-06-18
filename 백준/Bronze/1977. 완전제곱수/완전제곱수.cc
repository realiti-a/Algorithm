#include <iostream>
#include <vector>
using namespace std;

vector<int> squares;

int main(){
    int M, N; cin >> M >> N;
    for(int i = 1; i <= 100; i++) squares.push_back(i * i); 
    int minValue = 0, sum = 0;

    for(auto num : squares){
        if(num < M) continue;
        else if(num > N) break;

        if(!minValue) minValue = num;
        sum += num;
    }   
    if(!sum) cout << -1 << "\n";
    else cout << sum << "\n" << minValue << "\n";
    return 0;
}