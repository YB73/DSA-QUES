class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
       if(nums.size()<3) return 0;
        
        int finalAns=0;
        int n=nums.size();
        vector<int> helper;
        for(int i=1;i<nums.size();i++){
            int diff=nums[i]-nums[i-1];
            helper.push_back(diff);
        }

        for(int i=0;i<n-1;i++){
            int j=i+1;
            while(j<n-1 && helper[i]==helper[j]) j++;
        
            int num=j-i;
            i=j-1; // moving the loop counter ahead of equal elements
            if(num==1) continue;

            int ans=1;
            int value=2;
            for(int k=2;k<num;k++){
                ans+=value;
                value++;
            }
            finalAns+=ans;
        }
        return finalAns;
        
    }
};