class Solution {
public:
    string reverseVowels(string s) {
        string str = s;
        int start = 0;
        int end = s.size()-1;
 
        while(start < end) {
            bool v1 = false , v2 = false;
            char ch1 = tolower(str[start]);
            char ch2 = tolower(str[end]);

            if((ch1 == 'a' || ch1=='e' || ch1=='i' || ch1=='o' || ch1=='u'))
                v1=true;
            if((ch2 == 'a' || ch2=='e' || ch2=='i' || ch2=='o' || ch2=='u'))
                v2=true;

            if(v1 && v2)
                swap(s[start++],s[end--]);

            if(!v1)
                start++;
            if(!v2)
                end--;
        }
        return s;
    }
};