class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, numArray = 0;
        for(auto num: nums){
            if(num == 0){
                numArray++;
            }
            else 
                numArray = 0;
            ans += numArray;
        }
        return ans;
        
    }
};