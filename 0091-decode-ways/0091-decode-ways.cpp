class Solution {
public:
    int solve(string s , vector<int> &dp)
    {
        if(s.size()==0) return 1;
        if(dp[s.size()]!=-1) return dp[s.size()];
        int res = 0;
        if(s[0]!='0') res+=solve(s.substr(1),dp);
        if(s.size()>=2 && (s[0]=='1' || (s[0]=='2' && s[1]<='6')))
        {
            res+=solve(s.substr(2),dp);
        }
        return dp[s.size()] = res;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return solve(s,dp);
    }
};