class Solution {
public:
    int minCost(string s, vector<int>& t) {
        int n = s.length();
        int prev = 0, ans = 0;
        for(int i=1; i<n; i++){
            if(s[i] == s[prev]){
                if(t[prev] < t[i]){
                    ans += t[prev];
                    prev = i;
                } else{
                    ans += t[i];
                }
            }
            else{
                prev = i;
            }
        }
        return ans;
        
    }
};