class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // using gcd function
        if(str1 + str2 != str2 + str1){
            return "";
        }
        return str1.substr(0, gcd(size(str1), size(str2)));
        
    }
};