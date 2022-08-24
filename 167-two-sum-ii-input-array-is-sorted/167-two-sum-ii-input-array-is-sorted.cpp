class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int in = 0;
        int fin = n-1;
        while(in < fin){
            int s = numbers[in] + numbers[fin];
            if(s < target){
                in++;
            }
            else if(s > target){
                fin--;
            }
            else{
                return{in+1, fin+1};
            }
        }
        return {};
    }
};