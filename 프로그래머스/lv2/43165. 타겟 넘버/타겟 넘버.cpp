#include <string>
#include <vector>

using namespace std;

int sign[2] = {-1, 1};
vector<int> nums;
int targetNum;
int cnt = 0;

void dfs(int level, int start, int sum){
    if(level == nums.size()) {
        if(targetNum == sum) cnt++;
        return;
    }
    
    for(int i = start; i < nums.size(); i++){
        for(int j = 0; j < 2 ; j++){
            dfs(level + 1, i + 1, sum + nums[i] * sign[j]);
        }
    }
}

int solution(vector<int> numbers, int target) {
    nums = numbers;
    targetNum = target;
    dfs(0, 0, 0);
    return cnt;
}