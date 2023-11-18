class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long n = nums.size(), sum = 0, i=0, res = 0;
        for(int j=0; j<n; j++){
            sum += nums[j];
            while((j-i+1)*nums[j]-sum > k) sum -= nums[i++];
            res = max(res, j-i+1);
        }
        return res;
        
    }
};