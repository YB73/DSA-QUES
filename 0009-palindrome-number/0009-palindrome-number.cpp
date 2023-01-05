class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        return recursePal(s);
        
    }
    bool recursePal(string s){
        if(s.length() == 0 || s.length() == 1){
            return true;
        }
        else{
            if(s.at(0) == s.at(s.length() - 1)){
                return recursePal(s.substr(1, s.length() - 2));
            }
            else{
                return false;
            }
        }
    }
};