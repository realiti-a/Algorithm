#include <iostream>
#include <vector>
using namespace std;

int N, M, P;
//the number of pioneers : N
//the number of channels : M
//initial channel : P

vector<vector<int>> hatePeople;
vector<int> favouriteChannel;
vector<int> visitedChannel;
void input(){
    cin >> N >> M >> P;
    
    hatePeople = vector<vector<int>> (M + 1);
    favouriteChannel = vector<int> (N);
    visitedChannel = vector<int> (M + 1, 0);
    
    int favourite, hate;
    // 좋아하는 채널과 싫어하는 채널이 pioneers의 나이 순서대로 주어짐
    for(int i = 0; i < N; i++){
        cin >> favourite >> hate;
        favouriteChannel[i] = favourite;
        hatePeople[hate].push_back(i);
    }
}

int changeChannel(int now, int cnt){
    if(hatePeople[now].empty()){
        return cnt;
    }
    else if(visitedChannel[now]){
        return -1;
    }
    visitedChannel[now] = 1;
    cnt++;
    int to = favouriteChannel[hatePeople[now][0]];
    return changeChannel(to, cnt);
}

int main(){
    input();
    cout << changeChannel(P, 0) << "\n";
    return 0;
}
