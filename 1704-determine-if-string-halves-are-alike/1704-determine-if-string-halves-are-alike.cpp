class Solution {
public:
    bool halvesAreAlike(string s) {
        int f=0, t=0;
        for(int i=0;i<s.length();i++){
                        if(s[i]=='u'||s[i]=='o'||s[i]=='i'||s[i]=='e'||s[i]=='a'||s[i]=='U'||s[i]=='O'||s[i]=='I'||s[i]=='E'||s[i]=='A'){
            
            if(i<s.length()/2)
                f++;
            else
                t++;
        }
    }
    return f==t;
    }
};