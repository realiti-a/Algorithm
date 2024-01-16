#include <iostream>
#include <string>
using namespace std;

double whatScores(string s){
    if(s == "A+") return 4.5;
    else if(s == "A0") return 4.0;
    else if(s == "B+") return 3.5;
    else if(s == "B0") return 3.0;
    else if(s == "C+") return 2.5;
    else if(s == "C0") return 2.0;
    else if(s == "D+") return 1.5;
    else if(s == "D0") return 1.0;
    else if(s == "F" ) return 0.0;
    else return 0.0;
}

int main(){
    double totalScore = 0.0;
    double totalGrade = 0.0;
    for(int i = 0; i < 20; i++){
        string className; cin >> className;
        double score; cin >> score;
        string grade; cin >> grade;
        
        if(grade == "P") continue;

        totalScore += score;
        totalGrade += (score * whatScores(grade));
    }
    cout << fixed;
    cout.precision(6);
    cout << totalGrade / totalScore ;
    return 0;
}