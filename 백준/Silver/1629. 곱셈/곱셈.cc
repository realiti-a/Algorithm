#include <iostream>
using namespace std;

long long A, B, C;

long long product(long long factor){
    if(factor == 1) return A % C;
    if(factor % 2) return (product(factor - 1) * (A % C)) % C;

    long long halfRes = product(factor / 2); 
    return (halfRes * halfRes) % C;
}

int main(){
    cin >> A >> B >> C;
    cout << product(B) << "\n";
    return 0;
}
