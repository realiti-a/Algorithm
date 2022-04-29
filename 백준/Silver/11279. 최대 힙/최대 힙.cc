#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue< int, vector<int>, less<int> > q;
vector<int> res;

int main(){
    int N;
    cin >> N;

    int order;
    for(int i = 0; i < N; i++){
        cin >> order;

        if(order == 0){ 
            if(q.empty()) res.push_back(0);
            else {
                res.push_back(q.top());
                q.pop();
            }   
        }   
        else q.push(order);
    }   

    for(auto i : res) cout << i << "\n";

    return 0;
}