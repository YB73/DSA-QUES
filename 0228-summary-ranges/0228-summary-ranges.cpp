class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> temp;
        int n = nums.size();
        string ans = "";
        for(int i=0; i<n; i++){
            
            int j = i;
            while(j+1<n && nums[j+1] == nums[j] + 1) {
                j++;
            }
            
            if(j>i){
                ans += to_string(nums[i]);
                ans += "->";
                ans += to_string(nums[j]);
            }
            
            else{
                ans += to_string(nums[i]);
            }
            temp.push_back(ans);
            ans = "";
            i = j;
        }
        return temp;
    }
};