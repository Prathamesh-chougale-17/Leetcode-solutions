import java.util.*;

class Solution {
    public int countStaircase(int[] nums) {
        int n = nums.length;
        int sol = 0;

        for (int i = 0; i < n; i++) {
            HashMap<Integer, Integer> freq = new HashMap<>();
            ArrayList<Integer> order = new ArrayList<>();

            for (int j = i; j < n; j++) {
                int val = nums[j];

                if (freq.getOrDefault(val, 0) == 0) {
                    order.add(val);
                }

                freq.put(val, freq.getOrDefault(val, 0) + 1);

                boolean canbe = true;

                for (int k = 0; k < order.size(); k++) {
                    if (freq.get(order.get(k)) != k + 1) {
                        canbe = false;
                        break;
                    }
                }

                if (canbe) {
                    sol++;
                }
            }
        }

        return sol;
    }
}