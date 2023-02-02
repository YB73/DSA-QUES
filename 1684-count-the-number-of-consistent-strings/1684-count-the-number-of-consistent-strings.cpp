class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>s;
        int n=allowed.length();
        for(int i=0;i<n;i++)
        {
            s.insert(allowed[i]);
        }
        int c=0;
        bool flag;
        for(int i=0;i<words.size();i++)
        {
            // string ans=words[i];
            flag=true;
            for(int j=0;j<words[i].size();j++)
            {
                if(s.find(words[i][j])==s.end())
                {
                    flag=false;
                    // break;
                }
            }
            if(flag)c++;
        }
        return c;
    }
};