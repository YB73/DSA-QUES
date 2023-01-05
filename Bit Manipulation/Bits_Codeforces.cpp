#include <bits/stdc++.h>
using namespace std;

int main(){
    
  
 int t;
 long long L, R;
 long long res;
 cin>>t;
 while(t--){
  cin>>L>>R;
  res = L;
  for(int i=0; i<64; i++)
    if((res & (1LL<<i)) == 0){
        long long temp = res + (1LL<<i);
       if(temp > R) break;
       else res = temp;
  
  
 }
cout<<res<<endl;
}
 
}