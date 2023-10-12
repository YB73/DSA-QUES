class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> pre(n,0), suff(n,0), ans;
        for(int i=0;i<n;i++){
            if(i!=0 && security[i]<=security[i-1]) pre[i]+=pre[i-1]+1;
            else pre[i]=1;
        }
        for(int i=n-1;i>=0;i--){
            if(i!=n-1 && security[i]<=security[i+1]) suff[i]+=suff[i+1]+1;
            else suff[i]=1;
        }
        if(time==0) ans.push_back(0);
        for(int i=1;i<n-1;i++){
            if(pre[i]>time && suff[i]>time){
                ans.push_back(i);
            }
        }
        if(n>1 && time==0) ans.push_back(n-1);
        return ans;
    }
};