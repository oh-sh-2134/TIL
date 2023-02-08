import java.util.*;

class Solution {
    public String solution(int[] food) {
//        StringBuilder sb = new StringBuilder();
//
//        // food[0] : 물
//        for(int i = 1; i < food.length; i++) {
//            int division = food[i] / 2;
//
//            for(int j = 0; j < division; j++) {
//                sb.append(i);
//            }
//        }
//        String answer = sb.toString() + "0" + sb.reverse().toString();
//        return answer;
        String answer = "0";
        for(int i = food.length - 1; i > 0; i--) {
            for(int j = 0; j < food[i] / 2; j++) {
                answer = i + answer + i;
            }
        }
        return answer;
    }
}

class main{

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr ={1, 3, 4, 6};
        System.out.println("sol = " + sol.solution(arr));
    }

}
