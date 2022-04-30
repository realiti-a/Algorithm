#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

struct meeting {
    int start, end;
};

vector<meeting> schedule;

void input(){
    cin >> N;
    
    int startTime, endTime;
    for(int i = 0; i < N; i++){
        cin >> startTime >> endTime;
        schedule.push_back({startTime, endTime});
    }   
}

int comp(meeting a, meeting b){ 
    if(a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

int getMaxMeeting(){
    int cnt = 0;

    int now = 0;
    for(int i = 0; i < N; i++){
        if(schedule[i].start >= now){
            cnt++;
            now = schedule[i].end;
        }   
    }   

    return cnt;
}

int main(){
    input();
    
    //끝나는 시간을 기준으로 정렬
    sort(schedule.begin(), schedule.end(), comp);
    
    cout << getMaxMeeting() << "\n";
    return 0;
}