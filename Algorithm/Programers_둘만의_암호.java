import java.util.*;

class Solution {

    boolean [] skipChar = new boolean[26];

    public char converter(char c, int idx){
        while (idx >0){
            c++;
            if(c-'a' >= 26) c = 'a';
            if(skipChar[c-'a'])continue;
            idx--;
        }
        return c;
    }

    public String solution(String s, String skip, int index) {
        String answer = "";
        Arrays.fill(skipChar,false);
        for (char c : skip.toCharArray()) {
            skipChar[c-'a'] = true;
        }
        for (char c : s.toCharArray()) {
            answer += converter(c, index);
        }
        return answer;
    }
}

public class Programers_둘만의_암호{

    public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "aukks";
        String skip = "wbqd";
        int idx = 5;
        System.out.println("sol = " + sol.solution(s,skip,idx));
    }

}
