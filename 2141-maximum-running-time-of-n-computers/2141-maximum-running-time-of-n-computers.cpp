class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
             long long time=0;
        for(auto x:batteries)
        time+=x;
        sort(batteries.rbegin(),batteries.rend());
        for(int i=0;i<batteries.size();i++,n--){
            if(batteries[i]<=(time/n))
            break;
            time-=batteries[i];
        }
        return time/n;
        
        
    }
};