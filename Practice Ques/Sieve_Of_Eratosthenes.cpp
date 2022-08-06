// to print all prime numbers smaller than or equal to a given number n.

#include<bits\stdc++.h>
using namespace std;




void SieveOfEratosthenes(int n){

bool prime[n + 1];
memset(prime, true, sizeof(prime));




    for(int i = 2; i * i <= n; i++){
        if(prime[i]){
            for(int j=i * i; j<=n; j+=i){
                prime[j] = false;
            } 

        }

    }
     for(int i=2; i<=n; i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }

}





int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    SieveOfEratosthenes(n);
   
    return 0;
}