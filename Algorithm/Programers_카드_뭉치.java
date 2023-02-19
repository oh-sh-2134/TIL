import java.util.*;

class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "Yes";
        int pos1 = 0, pos2 = 0;
        for (String s : goal) {
            int total = pos1+pos2;
            if(cards1.length > pos1 && s.equals(cards1[pos1]))
                pos1++;
            else if(cards2.length > pos2 && s.equals(cards2[pos2]))
                pos2++;
            if(total == pos1+pos2)
                return "No";

        }
        return answer;
    }
}

class main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "banana";
        String s1[] = {"i", "drink", "drink"};
        String s2[] = {"want", "to"};
        String goal[] = {"i", "want", "to", "drink", "water"};
        System.out.println("sol = " + sol.solution(s1,s2,goal));
    }
}
//https://school.programmers.co.kr/learn/courses/30/lessons/159994