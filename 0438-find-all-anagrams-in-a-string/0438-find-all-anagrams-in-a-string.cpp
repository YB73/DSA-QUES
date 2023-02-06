class Solution {
public:
    bool isAnagram(int fs[],int fp[]){
        for(int i=0;i<26;i++){
            //If any point the frequency is not same then return false;
            if(fs[i]!=fp[i]){
                return false;
            }
        }
        //If the frequency is same return the true
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
      
        vector<int>ans;
        
        int n=s.size(),m=p.size();
       
        int fs[26]={0},fp[26]={0};
      
        for(int i=0;i<m;i++){
            fp[p[i]-'a']++;
        }
        
        for(int i=0;i<n;i++){
          
            if(i<m-1){
                fs[s[i]-'a']++;
            }
           
            else if(i==m-1){
                fs[s[i]-'a']++;
              
                if(isAnagram(fs,fp)){
                    ans.push_back(i-m+1);
                }
            }
           
            else{
                fs[s[i-m]-'a']--;
                fs[s[i]-'a']++;
                //checking if they are anagram
                if(isAnagram(fs,fp)){
                    ans.push_back(i-m+1);
                }
            }
        }
       
        return ans;
    }
};