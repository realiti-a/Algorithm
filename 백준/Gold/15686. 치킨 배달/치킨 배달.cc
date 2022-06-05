#include <iostream>
#include <vector>
using namespace std;

struct pos {int y, x;};

int N, M, result;
vector<pos> house;
vector<pos> chicken;
vector<pos> selectedChicken;

int houseSize, chickenSize;

int operator-(pos a, pos b) {return abs(a.y - b.y) + abs(a.x - b.x);}

void getDist(){
    int totalDist = 0;

    for(int i = 0; i < houseSize; i++){
        int minDist = 123456789;
        for(int j = 0; j < M; j++){
            int nowDist = house[i] - selectedChicken[j];
            if(nowDist < minDist) minDist = nowDist;
        }   
        totalDist += minDist;
    }   

    if(totalDist < result) result = totalDist;
}

void chooseChicken(int start, int level){
    if(level == M){ 
        getDist();
        return;
    }   
    for(int i = start; i < chickenSize; i++){
        selectedChicken.push_back(chicken[i]);
        chooseChicken(i + 1, level + 1); 
        selectedChicken.pop_back();
    }   
}

int main(){
    cin >> N >> M;

    int information;
    result = 123456789;
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++){
            cin >> information;
            if(information == 1) {
                house.push_back({y, x});
            }   
            else if(information == 2){ 
                chicken.push_back({y, x});
            }   
        }   
    }   

    houseSize = house.size();
    chickenSize = chicken.size();
    chooseChicken(0, 0);
    cout << result << "\n";

    return 0;
}