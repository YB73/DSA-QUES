class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avg(nums.size(),-1);
        long sum = 0;
        int left=0;
        int dia = 2*k+1;
        for(int right=0;right<nums.size();right++)
        {
            sum+=nums[right];
            if(right-left+1 >=dia)
            {
                avg[left+k] = sum/dia;
                sum-=nums[left];
                left++;
            }
        }
        return avg;
    }

    //     int n = nums.size();
    //     vector<int> ans(n,-1);
    //     long sum=0;
    //     int x = 2*k+1;
    //     if(x>n) return ans ;
    //     for(int i=0;i<x;i++) sum+=nums[i];
    //     sum=sum/x;
    //     for(int i=0;i<n;i++)
    //     {
    //         // if(i-k<0 || i+k >n) ans.push_back(-1);
    //         if(i>=k && i<=n-k)
    //         {
    //             ans[i]=sum;
    //             sum-=nums[i-k]/x;
    //             sum+=nums[i+k+1]/x;
    //         }
    //     }
    //     return ans;
    // }
};