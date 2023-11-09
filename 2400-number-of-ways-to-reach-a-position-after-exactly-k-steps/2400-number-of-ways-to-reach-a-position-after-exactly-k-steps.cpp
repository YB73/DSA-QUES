class Solution {
public:
    
    int M = 1e9+7;
    
    int f(int s, int e, int k, int i, vector<vector<int>> &dp){
		// base condition
        if(i==0) {
            if(s==e) {
                return 1;
            }
            else return 0;
        }
        
		// optimization
        if(abs(e-s)>i) return 0;
        if(dp[s+1000][i] != -1) {
            return dp[s+1000][i]%M;
        }
        
        // choices
        int left = f(s-1, e, k, i-1, dp)%M;
        int right = f(s+1, e, k, i-1, dp)%M;
        
        return dp[s+1000][i] = (left + right)%M;
    }
    
    int numberOfWays(int s, int e, int k) {
		// big array size to make sure we don't get runtime error
        vector<vector<int>> dp(3000, vector<int>(k+1, -1));
        return f(s, e, k, k, dp);
    }
};