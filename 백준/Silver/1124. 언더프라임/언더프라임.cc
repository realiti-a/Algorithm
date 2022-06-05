#include <iostream>
using namespace std;

int prime[100001];

//if PrimeNumber, then prime[i] == 0;
void makePrime(){
    prime[1] = 1; prime[0] = 1;
    for(int i = 2; i <= 100001; i++){
        if (prime[i]) continue;
        for(int j = 2; i * j <= 100001; j++){
            prime[i * j] = 1;
        }   
    }   
}

int isUnderPrime(int n){ 
    int cnt = 0;

    while(n != 1){ 
        int factor = 1;
        for(int i = 2; i <= n; i++){
            if(prime[i]) continue;
            if(n % i) continue;

            factor = i;
            break;
        }   
        n /= factor;
        cnt++;
    }   

    if(prime[cnt]) return 0;
    return 1;
}

int main(){
    makePrime();
    int A, B; cin >> A >> B;

    int cnt = 0;
    for(int i = A; i <= B; i++){
        cnt += isUnderPrime(i);
    }   
    cout << cnt << "\n";
    return 0;
}