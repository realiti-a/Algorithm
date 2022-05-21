#include <iostream>
using namespace std;

int N;
int arr[100] = {}; 

int getGCD(int a, int b){ 
    int r = a % b;
    return r ? getGCD(b, r) : b;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    for(int i = 1; i < N; i++){
        int gcd = getGCD(arr[i], arr[0]);
        cout << arr[0] / gcd << "/" << arr[i] / gcd << "\n";
    }   

    return 0;
}