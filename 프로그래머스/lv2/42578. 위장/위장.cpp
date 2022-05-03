#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, vector<string>> closet;

int solution(vector<vector<string>> clothes) {
    for(vector<string> cloth : clothes){
        //map 안에 키값이 있으면, value vector에 추가
        if(closet.find(cloth[1]) != closet.end()){
            closet[cloth[1]].push_back(cloth[0]);
        }
        //map 안에 키값이 없으면, value vector 만들기
        else {
            closet[cloth[1]] = vector<string>(1, cloth[0]);           
        }
    }
    
    int answer = 1;
    for(auto iter: closet){
        answer *= iter.second.size() + 1;
    }
    
    return answer - 1;
}