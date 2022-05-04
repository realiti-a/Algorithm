#include <iostream>

using namespace std;

int solution(int n, int a, int b){
    int answer = 0;
    
    while(a != b){
        if(a%2) a++;
        if(b%2) b++;
        
        a >>= 1;
        b >>= 1;
        answer++;
    }
    
    return answer;
}