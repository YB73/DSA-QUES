#include<bits/stdc++.h>
using namespace std;

// bool checkPrime(int n){
//     int cnt = 0;
//     for(int i=1; i*i<=n; i++){
//         if(n%i == 0){
//             cnt++;
//         if((n/i) != i){
//             cnt++;
//         }
//     }
// }
// if(cnt==2) return true;
// return false;
// }


int N = 1000000;
bool sieve[1000001];
void createSieve(int n){
    for(int i=2; i<=n; i++){
        sieve[i] = true;
    }
    for(int i=2; i*i<=n; i++){
        if(sieve[i] == true){
            for(int j=i*i; j<=n; j+=i){
                sieve[j] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++)
        if (sieve[p])
            cout << p << " ";

}
int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        cout<<"Primes less than or equal to n are"<<endl;
        createSieve(n);
        cout<<endl;
    }
    return 0;
}