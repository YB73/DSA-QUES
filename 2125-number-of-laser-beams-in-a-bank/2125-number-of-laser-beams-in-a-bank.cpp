
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0, prevcount = 0, ans = 0;
        // counting number of devices in first row
        for(int i=0; i<bank[0].size(); i++){
            if(bank[0][i] == '1'){
                prevcount++;
            }
        } 
        // counting row by row, devices in other rows
        for(int i=1; i<bank.size(); i++){
            for(int j=0; j<bank[i].size(); j++){
            // increasing the prevcount as many times as the current row ( because number of laser beams between two rows having n1 and n2 devices respectively will simply be n1*n2 --- according to pnc)
                if(bank[i][j] == '1'){
                    count++;
                    ans += (prevcount);
                }
            }
            // initializing count back to 0
            if(count){
                prevcount = count;
                count = 0;
            }
        }
        return ans;
        
    }
};
