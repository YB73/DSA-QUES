class Solution {
public:
   int dp[46];
    int solve(int n){
        if(dp[n] != -1)return dp[n];
        if(n == 1)return 1;
        if(n == 2)return 2;
        return dp[n] = solve(n - 1) + solve(n - 2);
    }
    int climbStairs(int n) {
        for(int i = 0; i < 46; i++){
            dp[i] = -1;
        }
        return solve(n);
    }
};