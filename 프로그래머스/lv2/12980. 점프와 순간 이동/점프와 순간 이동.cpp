#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n){
        if(n % 2) {
            ans++;
            n -= 1;
        }
        n >>= 1;
    }
    return ans;
}