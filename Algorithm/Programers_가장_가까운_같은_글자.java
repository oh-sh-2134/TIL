import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        Arrays.fill(answer,-1);
        HashMap<String, Integer> map = new HashMap<>();
        for(int i=0;i<s.length();i++){
            if(map.containsKey(Character.toString(s.charAt(i)))){
                answer[i] = i - map.get(Character.toString(s.charAt(i)));
            }
            map.put(Character.toString(s.charAt(i)),i);
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
