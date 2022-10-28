#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    answer += toupper(s[0]);
    for(int i=1;i<s.size();i++){
        if(s[i-1] == ' '){
            answer += toupper(s[i]);
            continue;
        }
        answer += tolower(s[i]);
    }
    return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12951