#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> buf;

int comp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    for(auto num : numbers){
        buf.push_back(to_string(num));
    }
    
    sort(buf.begin(), buf.end(), comp);
    
    for(auto s: buf){
        answer += s;
    }
    
    if(answer[0] == '0') return "0";
    return answer;
}