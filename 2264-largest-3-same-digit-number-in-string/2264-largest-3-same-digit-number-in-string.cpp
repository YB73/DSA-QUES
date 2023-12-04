class Solution {
public:
    string largestGoodInteger(string s) {
        
         int ans = -1;
        unordered_map<char, int> mp;
        for (int i = 0; i < 3; i++)
        {
            mp[s[i]]++;
        }
        if (mp.size() == 1)
            ans = s[2] - '0';
        for (int i = 3; i < s.length(); i++)
        {
            mp[s[i - 3]]--;
            mp[s[i]]++;
            if (mp[s[i - 3]] == 0)
                mp.erase(s[i - 3]);
            if (mp.size() == 1)
                ans = max(ans, (s[i] - '0'));
        }
        if (ans == -1)
            return "";
        string res;
        for (int i = 0; i < 3; i++)
            res += ans + '0';
        return res;
    }
};