class Solution {
public:
    bool SubsetSumToK(int n, int k, vector<int>&nums){
        vector<bool> prev(k+1,0);
        vector<bool> curr(k+1,0);
        prev[0] = curr[0] = true;
        if(nums[0] <= k) prev[nums[0]] = true;
        for(int ind=1; ind < n; ind++){
            for(int targ = 1; targ<=k; targ++){
                bool notTake = prev[targ];
                bool Take = false;
                if(nums[ind] <= targ) Take = prev[targ-nums[ind]];
                curr[targ] = Take | notTake;
            }
            prev = curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        for(int i=0; i<n; i++){
            totsum += nums[i];
        }
        if(totsum % 2) return false;
        int target = totsum/2;
        
        return SubsetSumToK(n,target,nums);
    }
};