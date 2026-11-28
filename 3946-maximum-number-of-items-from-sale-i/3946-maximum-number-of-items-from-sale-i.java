class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;
        int[][] tmp = new int[n][2];
        int mini = Integer.MAX_VALUE;

        int[] dp = new int[budget + 1];
        for (int i = 0; i < n; i++) {
            tmp[i][1] = items[i][1];
            mini = Math.min(mini, tmp[i][1]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (items[j][0] % items[i][0] == 0) {
                    tmp[i][0]++;
                }
            }
            for (int j = budget; j >= items[i][1]; j--) {
                dp[j] = Math.max(dp[j], dp[j - items[i][1]] + tmp[i][0]);
            }
        }

        // Arrays.sort(tmp, (a, b) -> {
        //     long x = (long) a[1] * b[0];
        //     long y = (long) a[0] * b[1];

        //     if (x == y) {
        //         return Integer.compare(a[1], b[1]);
        //     }

        //     return Long.compare(x, y);
        // });

        // int sol = 0;

        // for (int[] i : tmp) {
        //     if ((i[0] + 1) * mini < i[1]) break;

        //     if (i[1] <= budget) {
        //         sol += (i[0] + 1);
        //         budget -= i[1];
        //     }
        // }

        // while (budget >= mini) {
        //     sol++;
        //     budget -= mini;
        // }

        // return sol;
        int ans = 0;

        for (int i = 0; i <= budget; i++) {
            ans = Math.max(ans, dp[i] + (budget - i) / mini);
        }

        return ans;
    }
}