class Solution {
public:
   int solve(int index, int time,vector<int>& satisfaction,vector<vector<int>>&dp)
    {
        if(index>=satisfaction.size()) 
            return 0;
        if(dp[index][time]!= -1) return dp[index][time];
        int include=satisfaction[index]*(time+1)+solve(index+1,time+1,satisfaction,dp);
        int exclude=0+solve(index+1,time,satisfaction,dp);
        return dp[index][time]=max(include,exclude);
    }
    int solveBottomUp(vector<int>& satisfaction)
    {
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1, 0));
        //dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int t=i;t>=0;t--)
            {
                int include=satisfaction[i]*(t+1)+dp[i+1][t+1];
                int exclude=0+dp[i+1][t];
                
                dp[i][t]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        // int n=satisfaction.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1, -1));
        // return solve(0,0,satisfaction,dp);
        return solveBottomUp(satisfaction); 
    }
};