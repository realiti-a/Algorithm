#include <string>
#include <vector>

using namespace std;

int index[200] = {};

int solution(string word) {
    int answer = 0;
    
    int idx = 0;
    for(char c : "AEIOU"){
        index[c] = idx++;
    }
    
    int coeff = 3905;
    for(char c : word){
        coeff /= 5;
        answer += index[c] * coeff + 1;
    }
    
    
    return answer;
}