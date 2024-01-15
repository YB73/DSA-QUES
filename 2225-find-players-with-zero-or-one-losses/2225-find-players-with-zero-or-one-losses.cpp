class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> matchLostMp;
        for(auto match : matches){
           int winner = match[0], looser = match[1];
           if(!matchLostMp.count(winner))
            matchLostMp[winner] = 0;
           matchLostMp[looser]--;
        }
        vector<int> winners, loosers;
        for(auto &lostMatchEntry : matchLostMp){
            int lostCnt = lostMatchEntry.second, player = lostMatchEntry.first;
            if(lostCnt == 0){
                winners.push_back(player);
            }else if(lostCnt == -1){
                loosers.push_back(player);
            }
        }
        vector<vector<int>> res;
        res.push_back(winners);
        res.push_back(loosers);
        return res;
    }
};