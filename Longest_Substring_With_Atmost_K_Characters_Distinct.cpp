#include<vector>
#include<cmath>
#include<cstring>
int getLengthofLongestSubstring(int k, string s)
{
    int n = s.length();
     int start = 0;
     vector<int> f(26);
    int total_dis = 0;
    int maxlen = 0;
    for(int end = 0; end<n; end++){
        if(f[s[end] - 'a'] == 0){
            f[s[end] - 'a']++;
            total_dis++;
        }
        else f[s[end] - 'a']++;
        if(total_dis<=k) maxlen = max(maxlen, end-start+1);
        else{
            while(start < n && total_dis > k){
                f[s[start] - 'a']--;
                if(f[s[start] - 'a'] == 0) total_dis--;
                start++;
            }
        }
    
    
    }
    return maxlen;
}
