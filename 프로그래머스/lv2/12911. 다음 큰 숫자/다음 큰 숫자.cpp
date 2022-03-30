#include <string>
#include <vector>

using namespace std;

int countOne(int n){
    int count = 0;
    for(int i = 0; i <= 20; i++){
        if(n & (1 << i)) count++;
    }
    return count;
}

int solution(int n) {
    int NOne = countOne(n);
    for(int i = n + 1; i <= 2* n; i++){
        if(countOne(i) == NOne) return i;
    }
}