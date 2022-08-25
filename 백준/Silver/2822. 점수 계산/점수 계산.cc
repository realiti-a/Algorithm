#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define PEOPLE 8

struct record {
    int order, score;
};

bool operator< (record a, record b){ 
    return a.score > b.score;
}

int main(){
    vector<record> records(PEOPLE, {0, 0});

    for(int i = 0; i < PEOPLE; i++){
        cin >> records[i].score;
        records[i].order = i + 1;
    }   

    sort(records.begin(), records.end());

    int totalSum = 0;
    priority_queue<int, vector<int>, greater<int>> pq; 
    for(int i = 0; i < 5; i++){
        totalSum += records[i].score;
        pq.push(records[i].order);
    }   
    
    //출력부
    cout << totalSum << "\n";
    for(int i = 0; i < 5; i++){
        cout << pq.top() << " ";
        pq.pop();
    }   

    return 0;
}