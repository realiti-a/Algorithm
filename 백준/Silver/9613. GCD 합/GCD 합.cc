#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int N;

int getGCD(int a, int b){ 
    int r = a % b;
    return r ? getGCD(b, r) : b;
}

long long makePair(){
    long long sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            sum += getGCD(arr[i], arr[j]);
        }   
    }   
    return sum;
}

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> N;
        arr = vector<int>(N, 0); 
        for(int i = 0; i < N; i++) cin >> arr[i];
        cout << makePair() << "\n";
    }   
    return 0;
}