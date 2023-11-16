class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> freq(n+1,0);
        vector<int> res;
        for(auto ni : nums){
            freq[ni]++;
        }
        for(int i=1; i<=n; i++){
            if(!freq[i]) res.push_back(i);
        }
        return res;
    }
};