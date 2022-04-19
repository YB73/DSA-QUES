#include<bits/stdc++.h>
using namespace std;
int Climb(int n){
   if(n<=2){
       return n;
   }
   int first=1,second=2,ans=3;
        for(int i=3;i<=n;i++){
            ans = first+second;
            first = second;
            second = ans;
        }
        return ans;
}
int main(){
    int n;
    cout<<"Enter the top stair number "<<endl;
    cin>>n;
    cout<<"The number of steps required to reach to the top : ";
    cout<<" "<<Climb(n);
}