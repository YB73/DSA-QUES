class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int ,int> m;
        int missing = -1;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        for(int i=0; i<=n; i++){
            if(m[i] == 0){
                missing = i;
            }
        }
        return missing;
    }
};