class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>output;
    int i=0;
    while(i<nums.size()){
         int j=i+1;
         while(j<nums.size()&&(long long)nums[j]-nums[j-1]==1)j++;
         int k=j-1;
         if(i==k)output.push_back(to_string(nums[i]));
         else{
             output.push_back(to_string(nums[i])+"->"+to_string(nums[k]));
         }
         i=j;
    } 
    return output;  
    }
};