class Solution {
public:
    int solve(int idx, vector<vector<int>>& offers, vector<int> &dp){
        if(idx == offers.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int notTake = solve(idx+1,offers,dp);
        int low = idx+1 , high = offers.size()-1;
        int next_idx = offers.size();
        
         while (low <= high) {
            int mid = (low+high)/2;
            if (offers[mid][0] > offers[idx][1]) {
                high = mid - 1;
                next_idx = mid;
            } else {
                low = mid + 1;
            }
        }
          // finding profit max
        int take = offers[idx][2] + solve(next_idx, offers, dp);
        return dp[idx] = max(take, notTake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        sort(offers.begin(), offers.end());
        vector<int> dp(m,-1);
        return solve(0,offers,dp);
        
    }
};