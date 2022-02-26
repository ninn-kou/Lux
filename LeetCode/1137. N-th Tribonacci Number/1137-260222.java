// Hao Ren
// 26 February, 2022
// 1137. N-th Tribonacci Number

class Solution {
    public int tribonacci(int n) {
        int dp[] = new int[n < 3 ? 3 : n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
}
