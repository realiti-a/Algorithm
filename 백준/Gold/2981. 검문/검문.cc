#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;

int getGCD(int a, int b){ 
    int remain = a % b;
    return remain? getGCD(b, remain) : b;
}

int main(){
    cin >> N;
    arr = vector<int>(N, 0); 
    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int gcd = arr[1] - arr[0];
    for(int i = 2; i < N; i++) gcd = getGCD(gcd, arr[i] - arr[i - 1]);

    vector<int> result;
    for(int i = 2; i * i <= gcd; i++){
        if(gcd % i) continue;
        result.push_back(i);
        if(i * i == gcd) continue;
        result.push_back(gcd / i); 
    }   
    result.push_back(gcd);
    sort(result.begin(), result.end());

    for(int r : result) cout << r << " ";
    return 0;
}