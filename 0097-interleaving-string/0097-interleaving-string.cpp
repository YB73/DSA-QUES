class Solution {
public:
    bool helper(string &s1, string &s2, string &s3, int n, int m, int size, vector<vector<int>>& dp){
        if(n < 0 && m < 0 && size < 0) return true;
        if(n >= 0 && m >= 0 && dp[n][m] != -1) return dp[n][m];
        if(n >= 0 && s1[n] == s3[size] && m >= 0 && s2[m] == s3[size]) 
            return dp[n][m] = helper(s1, s2, s3, n-1, m, size-1, dp) or helper(s1, s2, s3, n, m-1, size-1, dp);
        else if(n >= 0 && s1[n] == s3[size])
            return helper(s1, s2, s3, n-1, m, size-1, dp);
        else if(m >= 0 && s2[m] == s3[size])
            return helper(s1, s2, s3, n, m-1, size-1, dp);
        else return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), size = s3.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        if(size != n + m) return false;
        return helper(s1, s2, s3, n-1, m-1, size-1, dp);
    }
};