class Solution {
public:
   bool helper(string s,string t){
        // character to character mapping 
        map<char,char> mapping;
        
        // size of s string to traverse it
        int str_len = s.size();
        
        // traversing s and t
        for(int i=0;i<str_len;i++){
            // check if a mapping already exists
            if(mapping.find(s[i])!=mapping.end()){
                // if it exists we want to check if output is same as our current char
                if(mapping[s[i]]!=t[i]) return false;
            }
            // if mapping doesn't exist yet, adds it
            else  mapping[s[i]]=t[i];
        }
        
        // if nothing fails, returns true;
        return true;
    }

    bool isIsomorphic(string s, string t) {
        // why and? s = "badc" t = "baba", our method(helper) fails for this case otherwise
        return helper(s,t) && helper(t,s);
    }
};