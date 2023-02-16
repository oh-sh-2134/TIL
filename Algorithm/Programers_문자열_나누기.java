import java.util.*;

class Solution {
    public static int solution(String s) {
        char x = ' ';
        int answer = 0, mCnt = 1, sCnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (x == ' ') {
                x = s.charAt(i);
                continue;
            }
            if (x == s.charAt(i)) {
                mCnt++;
            }else{
                sCnt++;
            }
            if (mCnt == sCnt) {
                answer++;
                x = ' ';
                mCnt = 1;
                sCnt = 0;
            }
        }
        if (x != ' ') {
            answer++;
        }

        return answer;
    }
}
class main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "banana";
        System.out.println("sol = " + sol.solution(s));
    }
}
//https://school.programmers.co.kr/learn/courses/30/lessons/140108