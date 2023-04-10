#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int maxSum = 0;
    int left = 0;
    vector<vector<int>> res;
    for (int right = 0; right < sequence.size(); right++) {
        while (maxSum < k && left < sequence.size()) {
            maxSum += sequence[left];
            left++;
        }
        if (maxSum == k) res.push_back({ right, left - 1, left - 1 - right });        
        maxSum -= sequence[right];
    }

    sort(res.begin(), res.end(), [](vector<int> a, vector<int> b) {
        if(a[2] == b[2]) return a[0] < b[0];
        return a[2] < b[2];
    });
    vector<int> answer = { res[0][0], res[0][1] };
    return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/178870
