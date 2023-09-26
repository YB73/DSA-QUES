class Solution {
public:
    string removeDuplicateLetters(string s) {
      vector<int>lastIndex(256, -1);
        
        for (int i = 0; i < s.size(); i++)
        {
            lastIndex[s[i]] = i;
        }
        
        stack<int> st;
        unordered_set<int>used;
        
        for (int i = 0; i < s.size(); i++)
        {
            // cout<<"\n"<<s[i]<<"\t";
            if (used.count(s[i])) continue;
            if (st.empty() || st.top() <= s[i])
            {
                if (!used.count(s[i]))
                {
                    // cout<<"push"<<"\t";
                    st.push(s[i]);
                    used.insert(s[i]);
                }
            }
            else if(st.size())
            {
                while(st.size() && st.top() > s[i] && lastIndex[st.top()] > i) 
                {
                    // cout<<"pop"<<(char)st.top()<<"\t";
                    used.erase(st.top());
                    st.pop();
                }
            }
                
            if (!used.count(s[i]))                    
            {
                 // cout<<"add used"<<s[i]<<"\t";
                st.push(s[i]);
                used.insert(s[i]);
            }
            
        }
        
        string ans = "";
        while(st.size())
        {
            ans += (char)st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};