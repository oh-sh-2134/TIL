import java.util.*;

class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i : ingredient) {
            stack.push(i);
            if(stack.size()<4) continue;
            if(stack.get(stack.size()-4) != 1
            || stack.get(stack.size()-3) != 2
            || stack.get(stack.size()-2) != 3
            || stack.get(stack.size()-1) != 1) continue;

            answer++;
            stack.pop();
            stack.pop();
            stack.pop();
            stack.pop();
        }
        return answer;
    }
}

class main{

    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = {2, 1, 1, 2, 3, 1, 2, 3, 1};
        System.out.println("sol = " + sol.solution(arr));
    }

}
