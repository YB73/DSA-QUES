#include<bits/stdc++.h>
using namespace std;
int main(){
    
   int t;
   int n, i;
   cin>>t;
   while(t--){
       cin>>n>>i;
       int mask = (1<<i) - 1; // shift 1 to ith position and subtract 1 so that all bits are set to 1 from 0 to i-1 position ( total i bits)
       int x = (n&mask);
       cout<<x<<endl;
   }
    return 0;
}