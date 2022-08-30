class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
    int n = nums.size();
    if(nums.size() == 1 && nums[0] > k){
        return 0;
    }
    if(nums.size() == 1 && nums[0] < k){
        return 1;
    }
   long long ke = k;
  long long p = 1;
    int res = 0;
    int end = 0;
    int start = 0;
    for(int start = 0, end=0 ; end<n; end++){
        p *= nums[end];
        while(start < end && p>=ke)
            p /= nums[start++];
        if(p < ke){
            int len = end-start+1;
            res += len;
        }
        
    }
    return res;
    }
};