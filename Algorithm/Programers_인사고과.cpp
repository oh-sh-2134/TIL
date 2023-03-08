#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    pair<int,int> wan = {scores[0][0], scores[0][1]};
    int wanSum = scores[0][0] + scores[0][1];
    int maxSecondScore = 0;
    auto comp = [](vector<int> a, vector<int> b){ return a[0] > b[0] || a[0] == b[0] && a[1] < b[1];};
    sort(scores.begin(), scores.end(), comp);
    for(auto iter : scores){
        if(wan.first < iter[0] && wan.second < iter[1]) return -1;
        if(maxSecondScore > iter[1]) continue;
        if(iter[0] + iter[1] > wanSum) answer++;
        maxSecondScore = iter[1];
    }
    return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/152995