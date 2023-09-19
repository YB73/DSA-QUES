class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
          int n = nums.size();
        for(auto &i: nums){
            if(i>n) i = n+1;
            if(i<=0)i = n+1;
        }
        for(auto &i: nums){
            if(abs(i)-1<n && nums[abs(i)-1]>0)nums[abs(i)-1] *= -1;
        }
        int i;
        for(i = 0; i < n; i++){
            if(nums[i]>0)return i+1;
        }
        return n+1;
    }
};