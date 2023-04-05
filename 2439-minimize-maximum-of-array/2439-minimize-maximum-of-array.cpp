class Solution {
public:
    typedef long long LONG;
    bool isValid(vector<int>& nums, int k){
        
        if (nums[0] > k) return false;
        LONG prev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            LONG d = k - prev;
            prev = nums[i] - d;
            if (prev > k) return false;
        }
        return true;
        
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        int ans;
        while(left<=right){
            int mid = (left+right)/2;
            if(isValid(nums, mid)) ans = mid, right = mid - 1;
            
            else left = mid + 1;
        }
        return ans;
    }
};