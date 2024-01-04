class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0, prevcount = 0, ans = 0;
        for(int i=0; i<bank[0].size(); i++){
            if(bank[0][i] == '1'){
                prevcount++;
            }
        }
        for(int i=1; i<bank.size(); i++){
            for(int j=0; j<bank[i].size(); j++){
                if(bank[i][j] == '1'){
                    count++;
                    ans += (prevcount);
                }
            }
            if(count){
                prevcount = count;
                count = 0;
            }
        }
        return ans;
        
    }
};