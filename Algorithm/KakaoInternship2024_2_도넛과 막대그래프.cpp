#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Node {
public:
    int in = 0;
    int out = 0;
};

unordered_map<int, Node> nodes;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    for (auto iter : edges) {
        nodes[iter[0]].out++;
        nodes[iter[1]].in++;
    }
    unordered_map <int, Node> ::iterator it;
    for (it = nodes.begin(); it != nodes.end(); it++) {
        //����
        if (it->second.out == 0)
            answer[2]++;
        //8��
        else if (it->second.out == 2 && it->second.in > 0)
            answer[3]++;
        //����
        else if (it->second.out >= 2 && it->second.in == 0)
            answer[0] = it->first;
    }
    //������
    answer[1] = nodes[answer[0]].out - answer[2] - answer[3];

    return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/258711