class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int i = 0, j = 1;
        vector<int> dp(n+1,0);
        while(j < n){
            if(s[i] == s[j]) dp[++j] = ++i;
            else if(i == 0) j++;
            else i = dp[i];
        }
        return dp[n] && dp[n]%(n-dp[n])==0;
    }
};