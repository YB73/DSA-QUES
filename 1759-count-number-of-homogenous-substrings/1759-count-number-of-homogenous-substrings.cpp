class Solution {
public:
    int m = 1e9 + 7;
    int countHomogenous(string s) {
        int count = 0;
        if(s.size() == 0) return 0;
        vector<int> leni(s.size(),0);
        leni[0] = 1;
        int res = 1;
        for(int i=1; i<s.size(); i++){
            leni[i] = 1;
            if(s[i] == s[i-1]){
                leni[i] = (leni[i]%m + leni[i-1]%m)%m;
            }
            res = (res%m + leni[i]%m)%m;
        }
        return res;
        
    }
};