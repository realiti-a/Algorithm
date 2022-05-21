#include <iostream>
using namespace std;

long long getGCD(long long a, long long b){ 
    long long r = a % b;
    return r ? getGCD(b, r) : b;
}

int main(){
    long long A, B;
    cin >> A >> B;
    
    long long gcd = getGCD(A, B); 
    long long lcm = A * B / gcd;
    cout << lcm << "\n";

    return 0;
}