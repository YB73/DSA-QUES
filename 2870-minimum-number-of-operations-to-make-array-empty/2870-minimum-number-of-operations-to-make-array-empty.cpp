class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x: nums){
            mp[x]++;
        }
        int ans=0;
        for(auto it: mp){
            int f = it.second;
            ans+=f/3;
            f=f%3;
            if(f==1){
                if(it.second/3>=1)
                    ans++;
                else
                    // cout<<it.first<<" "<<it.second<<" "<<f/3<<endl;
                    return -1;
            }
            else if(f==2)
                ans++;
        }
        return ans;
    }
};