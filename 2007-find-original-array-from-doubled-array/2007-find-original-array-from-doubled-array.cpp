class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        multiset<int> s;
        for(auto e : changed){
            s.insert(e);
        }
        vector<int> ans;
        while(s.size()){
           int ele = *s.begin();
        s.erase(s.find(ele));
            if(s.find(2*ele)==s.end())
            return {};
             s.erase(s.find(2*ele));
            ans.push_back(ele);
        }
        return ans;
    }
};