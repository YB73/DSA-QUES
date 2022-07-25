class Solution {
public:
    string addBinary(string a, string b) {
   ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
        int p=a.size()-1,q=b.size()-1;
        string ans;
        int sum=0,carry=0;
       
        while(p>=0||q>=0)
        {
            int u=p>=0?a[p]-'0':0;
            int v=q>=0?b[q]-'0':0;
            
            sum = u^v^carry;
            carry=(u+v+carry)>1?1:0;
            p--;q--;
            ans+=to_string(sum);
        }
        if(carry) ans+="1";
        reverse(begin(ans),end(ans));
        return ans;
    }
};