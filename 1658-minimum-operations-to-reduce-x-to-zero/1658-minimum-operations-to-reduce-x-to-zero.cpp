class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int sum = 0, n = nums.size();
        for(int i=0;i<n;i++)sum=sum+nums[i];
        int new_sum = sum - x;
        if(*min_element(nums.begin(),nums.end()) > x)return -1;
        if(sum < x) return -1;
        // int l=0,r=0;
        int l = 0;
        int curr_sum = 0,max_len = INT_MIN;
        for(int r=0;r<n;r++){
            curr_sum = curr_sum + nums[r];
            while(l<=r && curr_sum > new_sum){
                    curr_sum = curr_sum - nums[l];
                    l++;
                }
            if(curr_sum == new_sum) max_len = max(max_len,r-l+1);
            }
            return n - max_len;
        
    }
};