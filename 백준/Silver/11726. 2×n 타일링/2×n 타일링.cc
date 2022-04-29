#include <iostream>
using namespace std;

int res[1001] = {}; 
int N;

int main(){
    cin >> N;

    res[0] = 1;
    res[1] = 1;

    for(int i = 2; i <= N; i++){
        res[i] = (res[i - 1] + res[i - 2]) % 10007;
    }   

    cout << res[N] << "\n";
    return 0;
}