#define ll long long
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        ll p1[n],p2[n];
        p1[0]=nums[0];
        p2[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            p1[i]=(p1[i-1]+nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            p2[i]=(p2[i+1]+nums[i]);
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(p1[i]>=p2[i+1])cnt++;
        }
        return cnt;

        
    }
};