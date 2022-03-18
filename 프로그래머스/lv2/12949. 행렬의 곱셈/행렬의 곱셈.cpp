#include <string>
#include <vector>

using namespace std;

int dotProduct(vector<int> a, vector<vector<int>> b, int j){
    int sum = 0;
    for(int k = 0; k < a.size(); k++){
        sum += a[k] * b[k][j];
    }
    return sum;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    answer = vector<vector<int>> (arr1.size(), vector<int> (arr2[0].size()));
    for(int y = 0; y < arr1.size(); y++){
        for(int x = 0; x < arr2[0].size(); x++){
            answer[y][x] = dotProduct(arr1[y], arr2, x);
        }
    }
    return answer;
}