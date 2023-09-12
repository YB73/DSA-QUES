class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>m;
            for(auto ch:s)
            {
                    m[ch]++;
            }
        set<int> st;
        int ans=0; // the min deletions
        for(auto [num,cnt] : m){
            if(st.find(cnt) == st.end()){
                st.insert(cnt);
            }
            else{
                while(st.find(cnt) != st.end() && cnt>0){
                    ans++;
                    cnt--;
                }
                if(cnt>0) st.insert(cnt);
            }
        }
        return ans;
    }
};