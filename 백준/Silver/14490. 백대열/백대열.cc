#include <iostream>
#include <string>
using namespace std;

string str;

int getGCD(int a, int b){ 
    int r = a % b;
    return r ? getGCD(b, r) : b;
}

int main(){
    cin >> str;
    int pos = str.find(":");
    
    int n = stoi(str.substr(0, pos));
    int m = stoi(str.substr(pos + 1));

    int gcd = getGCD(n, m); 
    cout << n / gcd << ":" << m / gcd << "\n";
    return 0;
}