struct Compare {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for(auto itr= mp.begin(); itr!=mp.end(); itr++){
            pq.push({itr->second,itr->first});
            
        }
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};