#include <string>
#include <vector>

using namespace std;

vector<int> fibNum = {0, 1};

int solution(int n) {
    if(n >= fibNum.size()){
        fibNum.push_back((solution(n - 2) + solution(n - 1)) % 1234567);
    }
    return fibNum[n];
}