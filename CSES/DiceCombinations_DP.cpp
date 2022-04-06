#include<bits/stdc++.h>
#define ll long long
#define fr(a,b) for(int i=a;i<b;i++)
#define mod 1000000007
using namespace std;
// dp[i] = no. of valid ways to throw a dice s.t sum = i
// dp(n) ke liye we need to know dp(i)
// dp(i) = dp(i-1) (we can either throw a 1) + dp(i-2)(we can either throw a 2 ) + dp(i-3) (either a 3) + ............ + dp(i-6) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,m,x,i,j;
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        vector<ll> dp(n+1,0);
        dp[0] = 1;
        fr(1,n+1){

            for(int x = 1;x<=6;x++){
                if(x>i)
                break;

                dp[i] = (dp[i] + dp[i-x]) % mod;

            }
        }
        cout<< dp[n] << endl;

    }
    return 0;
    
}