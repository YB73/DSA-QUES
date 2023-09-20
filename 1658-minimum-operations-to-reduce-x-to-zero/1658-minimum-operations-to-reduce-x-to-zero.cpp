class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         int n = nums.size();
        if(n == 1 && nums[0] != x) return -1;
        vector<int> prefix;
        prefix.push_back(0);

        int sum = 0;
        for(int i =0;i < n ;i++){
            sum += nums[i];
            prefix.push_back(sum);
        }
        if(sum < x) return -1;
        if(sum == x) return n;
        unordered_map<int,int> suff;

        for(int i = 0;i < n; i++){
            suff[sum] = i;
            sum -= nums[i];

        }
        suff[0] = n;

        // Main Logic

        int noOfOps = INT_MAX;

        int i = 0;
        while(prefix[i] <= x){
            int target = x - prefix[i];

            if(suff[target]){
                noOfOps = min(noOfOps, i + n - suff[target]);
            }
            i++;
        }
        if(noOfOps == INT_MAX) return -1;
        return noOfOps;
        
    }
};