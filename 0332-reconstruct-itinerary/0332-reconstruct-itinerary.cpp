#define pb push_back
class Solution {
public:
    vector<string> res;
    map<string, vector<string>> mp;
    void dfs(string destination) {
        while (!mp[destination].empty()) {
            string nextDestination = mp[destination].back();
            mp[destination].pop_back();
            dfs(nextDestination);
        }
        res.push_back(destination);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket : tickets){
            string from= ticket[0];
            string to = ticket[1];
            mp[from].pb(to);
        }
        for(auto& m : mp){
            sort(m.second.rbegin(),m.second.rend());
        }
        string start = "JFK";
        dfs(start);
        reverse(res.begin(),res.end());
        return res;
    }
};