class Solution {
public:
    bool static compare(pair<int, int>&a, pair<int, int>&b){
        if(a.first == b.first) return a.second > b.second;
        
        return a.first > b.first;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> plants;
        for(int i=0; i<plantTime.size(); i++){
            plants.push_back({growTime[i], plantTime[i]});
        }
        sort(plants.begin(), plants.end(), compare);
        int tp = 0;
        int tg = 0;
        for(int i=0; i<plants.size(); i++){
            tp += plants[i].second;
            tg = max(tg, tp+plants[i].first);
        }
        return tg;
    }
};