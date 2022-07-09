#include<bits\stdc++.h>
#include<array>
#include<cmath>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
string countAndSay(int n){
    vector<string> dp(n+1);
    dp[1] = "1";
    vector<string> conv = {" ", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    for(int i=2;i<=n;i++){
        int c = 1;
        for(int j=1;j<dp[i-1].length();j++){
            if(dp[i-1][j] == dp[i-1][j-1]){
                c++;
            }
            else{
                dp[i] += conv[c];
                dp[i] += dp[i-1][j-1];
                c = 1;
            }
        }
            dp[i] += conv[c];
            dp[i] += dp[i-1].back();

        }
        return dp.back();
    }

int main(){
    int n;
    cout<<"Enter the number "<<endl;
    cin>>n;
    string x = countAndSay(n);
    cout<<x<<endl;
    
}