class Solution {
    /**
     * Java solution for LeetCode problem No.70
     * Climbing Stairs - Dynamic Programming
     * 10 November, 2021
     * @author          Hao Ren, hao.ren@student@unsw.edu.au
     * @precondition    int n > 0; when n == 1 return 1;
     */
    public int climbStairs(int n) {
        // Defensive programming;
        assert n > 0;
        if (n == 1) {
            return 1;
        }
        // Array deceleration;
        int dp[];
        // Allocating memory to array;
        dp = new int[n + 1];

        // dp initial conditions; no need to care about dp[0];
        dp[1] = 1;
        dp[2] = 2;

        // dp transition equation;
        for (int i = 3; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
