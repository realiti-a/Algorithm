#include <string>
#include <vector>

using namespace std;

vector<int> fibNum;

int solution(int n) {
    fibNum.push_back(0);
    fibNum.push_back(1);
    
    for(int i = 2; i <= n; i++){
        fibNum.push_back((fibNum[i - 2] + fibNum[i - 1])%1234567);
    }
    
    return fibNum[n];
}