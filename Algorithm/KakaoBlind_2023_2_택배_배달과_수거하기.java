import java.util.*;
class Solution {

    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        Stack<Integer> deliveriesInfo = new Stack<>();
        Stack<Integer> pickupsInfo = new Stack<>();

        for (int delivery : deliveries) {
            deliveriesInfo.push(delivery);
        }

        for (int pickup : pickups) {
            pickupsInfo.push(pickup);
        }

        while(!deliveriesInfo.empty() && deliveriesInfo.peek().equals(0))
            deliveriesInfo.pop();

        while(!pickupsInfo.empty() && pickupsInfo.peek().equals(0))
            pickupsInfo.pop();

        while ((!deliveriesInfo.empty()) || (!pickupsInfo.empty())) {
            answer += Math.max(deliveriesInfo.size(), pickupsInfo.size())*2;
            int box = 0;
            while (!deliveriesInfo.empty() && cap >= box) {
                int next = deliveriesInfo.pop();

                if (box + next <= cap) {
                    box += next;
                }else{
                    deliveriesInfo.push(next - cap + box);
                    break;
                }
            }

            box = 0;

            while (!pickupsInfo.empty() && cap >= box) {
                int next = pickupsInfo.pop();

                if (box + next <= cap) {
                    box += next;
                }else{
                    pickupsInfo.push(next - cap + box);
                    break;
                }
            }
        }


        return answer;
    }
}

class KakaoBlind_2023_2_택배_배달과_수거하기{

    public static void main(String[] args) {
        Solution sol = new Solution();
        String[][] s ={{"09:10", "10:10"}, {"10:20", "12:20"}};
//        System.out.println("sol = " + sol.solution(s));
    }

}
