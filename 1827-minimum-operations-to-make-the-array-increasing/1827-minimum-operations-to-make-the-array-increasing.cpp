class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0, n = nums.size();
        for(int i=1; i<n; i++){
            int temp = nums[i];
            nums[i] = max(nums[i], nums[i-1]+1);
            count += nums[i]-temp;
        }
        return count;
    }
};