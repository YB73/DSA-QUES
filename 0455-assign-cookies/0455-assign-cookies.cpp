class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, i = 0;
        for(int x: g)
        {
            while(i<s.size() && s[i]<x)
                i++;
            if(i==s.size()) return ans;
            ans++;
            i++;
        }
        return ans;
    }
};