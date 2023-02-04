class Solution {
public:
    bool isPermutation(string s, string t){
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }       
        for(auto it: mp){
            if(it.second != 0) return false;
        }       
        return true;
        
    }
    bool checkInclusion(string s1, string s2) {
       int n = s1.length(), m = s2.length();
        for(int i=0; i<=m-n; i++){
            string temp = s2.substr(i, n);
            if(isPermutation(s1,temp)){
                return true;
            }
        }
        return false;
    }
};