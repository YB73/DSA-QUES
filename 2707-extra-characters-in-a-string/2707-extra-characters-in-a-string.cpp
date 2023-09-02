class Solution {
public:
        int rec(int idx,vector<int> &dp,set<string> &mp,string &s){
                if(idx==s.size()){
                        return 0;
                }
                string t="";
                int ans=1e8;
                if(dp[idx]!=-1) return dp[idx];
                for(int i=idx;i<s.size();i++){
                  t+=s[i];
                        if(mp.find(t)!=mp.end()){
                                ans=min(ans,rec(i+1,dp,mp,s));
                        }
                        ans=min(ans,int(t.size()+rec(idx+1,dp,mp,s)));
                }
                return dp[idx]=ans;
        }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> mp(dictionary.begin(),dictionary.end());
            vector<int> dp(100,-1);
            int ans= rec(0,dp,mp,s);
            // for(auto i:dp){
            //         cout<<i<<" ";
            // }
            return ans;
    }
};