#include <iostream>
using namespace std;

long long getGCD(long long A, long long B){ 
    long long r = A % B;
    return r ? getGCD(B, r) : B;
}

int main(){
    int T;
    cin >> T;
    
    long long A, B;
    for(int i = 0; i < T; i++){
        cin >> A >> B;
        long long gcd = getGCD(A, B); 
        long long lcd = A * B / gcd;
        cout << lcd << "\n";
    }   
    return 0;
}