#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = phone_number;
    for(int i=0;i<answer.size()-4;i++) answer[i] = '*';
    return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12948
