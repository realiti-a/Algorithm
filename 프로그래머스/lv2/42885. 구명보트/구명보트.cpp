#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), less<int>());
    
    int boat = 0;
    int start = 0, last = people.size() - 1;
    
    while(start <= last){
        if(limit - boat >= people[last]){
            boat += people[last--];
        }
        else if(limit - boat >= people[start]){
            boat += people[start++];
        }
        else {
            boat = 0;
            answer++;
        }
    }
    
    if(boat) answer++;
    return answer;
}