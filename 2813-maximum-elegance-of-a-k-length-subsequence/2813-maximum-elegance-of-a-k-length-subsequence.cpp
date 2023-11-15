using ll = long long;
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        });
        unordered_set<int> vis;
        priority_queue<int, vector<int>, greater<int> > heap;
        ll tot = 0;
        for(int i = 0;i<k;++i) {
            auto x = items[i];
            if(vis.count(x[1])) heap.push(x[0]);
            else vis.insert(x[1]);
            tot += x[0];
        }
        ll ans = tot + (ll)vis.size() * (ll)vis.size();
        for(int i = k;i<items.size();++i) if(!heap.empty()) {
            auto x = items[i];
            if(!vis.count(x[1])) {
                vis.insert(x[1]);
                tot -= heap.top(); heap.pop();
                tot += x[0];
                ans = max(ans, tot + (ll)vis.size() * (ll)vis.size());
            }
        }
        return ans;
    }
};