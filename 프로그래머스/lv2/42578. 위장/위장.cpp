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
    //각 옷 종류마다 아예 안입기, 하나씩 꺼내 입기 의 선택지가 있어 사이즈보다 하나의 경우의 수가 더 있다.
    for(auto iter: closet){
        answer *= iter.second.size() + 1;
    }
    //대신에 모두 안 입는 경우는 제외해 줘야 한다.
    return answer - 1;
}