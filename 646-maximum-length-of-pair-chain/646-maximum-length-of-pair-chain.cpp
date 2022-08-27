class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n ,1);
        int maxm = 1;
        for(int i=1;i<n;i++){
            int temp = 0;
            for(int j=i-1;j>=0;j--){
                if(pairs[i][0] > pairs[j][1]){
                    temp = max(temp,dp[j]);
                }
            }
            dp[i]+=temp;
            maxm=max(maxm,dp[i]);
        }
        return maxm;
    }
};