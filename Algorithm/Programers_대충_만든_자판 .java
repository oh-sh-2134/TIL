import java.util.*;

import java.util.*;
class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        int[] answer = new int[targets.length];
        HashMap<Character,Integer> map = new HashMap<>();

        for (String key : keymap) {
            for (int i = 0; i < key.length(); i++) {
                char ch = key.charAt(i);
                if (!map.containsKey(ch)){
                    map.put(ch,i+1);
                    continue;
                }
                if(map.get(ch)>i){
                    map.replace(ch,i+1);
                }

            }
        }

        for(int i=0; i< targets.length;i++){
            int sum = 0;
            for(int j=0; j<targets[i].length();j++){

                char ch = targets[i].charAt(j);

                if(!map.containsKey(ch)){
                    sum = -1;
                    break;
                }
                sum+=map.get(ch);
            }
            answer[i] = sum;
        }

        return answer;
    }
}
class main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        String keymap[] = {"ABACD", "BCEFD"};
        String targets[] = {"ABCD","AABB"};
        System.out.println("sol = " + sol.solution(keymap,targets));
    }
}
//https://school.programmers.co.kr/learn/courses/30/lessons/160586