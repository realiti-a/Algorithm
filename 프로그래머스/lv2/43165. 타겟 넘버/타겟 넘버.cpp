#include <string>
#include <vector>

using namespace std;

int sign[2] = {-1, 1};
vector<int> nums;
int targetNum;

int dfs(int level, int sum){
    if(level == nums.size()) {
        if(targetNum == sum) return 1;
        return 0;
    }
    
    int res = 0;
    for(int i = 0; i < 2; i++){
        res += dfs(level + 1, sum + sign[i] * nums[level]);
    }
    return res;
}

int solution(vector<int> numbers, int target) {
    nums = numbers;
    targetNum = target;
    return dfs(0, 0);
}