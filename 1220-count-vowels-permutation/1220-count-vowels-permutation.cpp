class Solution {
public:
   
    int countVowelPermutation(int n) {
          const int MOD = 1000000007;
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        for (int i = 0; i < 5; i++) {
            dp[1][i] = 1;
        }
        for (int len = 2; len <= n; len++) {
            dp[len][0] = (dp[len - 1][1] + dp[len - 1][2] + dp[len - 1][4]) % MOD;
            dp[len][1] = (dp[len - 1][0] + dp[len - 1][2]) % MOD;
            dp[len][2] = (dp[len - 1][1] + dp[len - 1][3]) % MOD;
            dp[len][3] = dp[len - 1][2];
            dp[len][4] = (dp[len - 1][2] + dp[len - 1][3]) % MOD;
        }
        long long count = 0;
        for (int i = 0; i < 5; i++) {
            count = (count + dp[n][i]) % MOD;
        }
        return static_cast<int>(count); 
    }
};