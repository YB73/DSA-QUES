class Solution {
public:
    int maximum69Number (int num) {
        string nums = to_string(num);
        for(auto &curcar : nums){
            if(curcar == '6'){
                curcar = '9';
                break;
            }
        }
        return stoi(nums);
    }
};