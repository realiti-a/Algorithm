#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int N, M;

map<string, int> stringDict;
vector<string> intDict;

void input(){
    cin >> N >> M;

    intDict = vector<string> (1, "");
    string name;

    for(int i = 1; i <= N; i++){
        cin >> name;
    
        //name으로 찾기 위한 사전과 순서로 찾기 위한 사전 두 개 준비
        stringDict.insert({name, i});
        intDict.push_back(name);
    }   
}

void print(){
    string order;
    for(int i = 0; i < M; i++){
        cin >> order;

        if(order[0] >= '0' && order[0] <= '9') cout << intDict[stoi(order)] << "\n";
        else cout << stringDict.find(order)->second << "\n";
    }   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    print();    
    return 0;
}