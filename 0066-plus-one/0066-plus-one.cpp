class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        for(int i=n; i>=0; i--){
            // traversing the digits in backward fashion
            if(digits[i] == 9){
                digits[i] = 0;
            }
            else{
                digits[i] += 1;
                return digits;
            }
        }
        // if suppose the number is 999, then after the above loop the digits array will be = [000]
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};