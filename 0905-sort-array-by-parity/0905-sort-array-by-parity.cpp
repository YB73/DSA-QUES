class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res;
        int i = 0, j= nums.size() - 1, n = nums.size();
        while(i < j){
            if(nums[i]%2 != 0){
                swap(nums[i], nums[j]);
                --j;
            }
            else{
                ++i;
            }
        }
        return nums;
        
    }
};