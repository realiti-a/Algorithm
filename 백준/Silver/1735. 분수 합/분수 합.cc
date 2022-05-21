#include <iostream>
using namespace std;

int num1[2] = {}; 
int num2[2] = {}; 

int getGCD(int a, int b){ 
    int r = a % b;
    return r ? getGCD(b, r) : b;
}

int main(){
    //index 0 : 분자, index 1 : 분모
    cin >> num1[0] >> num1[1];
    cin >> num2[0] >> num2[1];

    int numerator = num1[0] * num2[1] + num1[1] * num2[0];
    int denominator = num1[1] * num2[1];

    int gcd = getGCD(numerator, denominator);
    
    cout << numerator / gcd << " " << denominator / gcd << "\n";
    
    return 0;
}