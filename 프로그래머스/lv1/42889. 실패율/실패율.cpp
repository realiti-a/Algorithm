#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct stage {
    int stageNumber;
    double looseRate;
};

bool comp(stage a, stage b) {
    if (a.looseRate == b.looseRate) {
        return a.stageNumber < b.stageNumber;
    }
    return a.looseRate > b.looseRate;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> people(502, 0);
    vector<stage> status;

    for (int i = 0; i < stages.size(); i++) {
        people[stages[i]]++;
    }

    int total = 0;
    double rate;

    for (int i = 501; i >= 1; i--) {
        total += people[i];
        if (total == 0) rate = 0;
        else {
            rate = (double)(people[i]) / total;
        }
        status.push_back({ i, rate });
    }

    sort(status.begin(), status.end(), comp);

    for (int i = 0; i < status.size(); i++) {
        if (status[i].stageNumber <= N) {
            answer.push_back(status[i].stageNumber);
        }
    }

    return answer;
}
