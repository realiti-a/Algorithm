#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

int main(){
    int N;
    cin >> N;

    int order;
    for(int i = 0; i < N; i++){
        cin >> order;
        if(order == 0){ 
            if(pq.empty()) cout << 0 << "\n";
            else {
                int next = pq.top().first;
                int nextSign = pq.top().second;
                pq.pop();

                cout << next * nextSign << "\n";
            }   
        }   
        else {
            if(order < 0){ 
                pq.push(make_pair(-order, -1));
            }   
            else {
                pq.push(make_pair(order, 1));
            }   
        }   
    }    

    return 0;
}