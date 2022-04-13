#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i = left ; i <= right; i++){
        int num;
        
        if(i / n >= i % n) num = i / n + 1;
        else num = i % n + 1;
        
        answer.push_back(num);
    }
    return answer;
}