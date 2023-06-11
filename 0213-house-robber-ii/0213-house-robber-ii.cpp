class Solution {
public:
    int rob(vector<int>& nums) {
          if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        else if (nums.size() == 3) return *max_element(nums.begin(), nums.end());
        else if (nums.size() == 4) return max(nums[0]+nums[2], nums[1]+nums[3]);
        vector<int> dp0 = {nums[0], nums[1], nums[0]+nums[2]};
        vector<int> dp1 = {nums[1], nums[2], nums[1]+nums[3]};
        for (int i = 4; i < nums.size(); i++){
            int prev = dp1[1];
            dp1[1] = max(dp1[2], dp1[0]);
            dp1[2] = max(prev + nums[i], dp1[0] + nums[i]);
            dp1[0] = max(dp1[0], prev);
        }
        for (int i = 3; i < nums.size() - 1; i++){
            int prev = dp0[1];
            dp0[1] = max(dp0[2], dp0[0]);
            dp0[2] = max(prev + nums[i], dp0[0] + nums[i]);
            dp0[0] = max(dp0[0], prev);
        }
        return max(*max_element(dp1.begin(), dp1.end()), *max_element(dp0.begin(), dp0.end()));
    }
};