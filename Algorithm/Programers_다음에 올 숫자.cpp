#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    bool flag = false;
    int idx = common[1] - common[0];
    for(int i = 1;i< common.size();i++){
        if(idx != common[i] - common[i-1]){
            flag = true;
            break;
        }
    }
    answer = idx + common[common.size()-1];
    if(flag){
        answer = (common[1]/common[0])*common[common.size()-1];
    }
    return answer;
}
/*
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    if(common[0] - common[1] == common[1] - common[2]){
        return common.back() - (common[0] - common[1]);
    }
    else{
        return common.back() * (common[1] / common[0]);
    }
    return answer;
}
*/
//https://school.programmers.co.kr/learn/courses/30/lessons/120924
