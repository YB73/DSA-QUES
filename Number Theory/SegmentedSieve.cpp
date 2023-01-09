// A segmented sieve problem

#include<bits/stdc++.h>
using namespace std;
const int N = 1000000;
int sieve[N+1];
void createSieve(){
    for(int i=2; i<=N; i++){
        sieve[i] = true;
    }
    for(int i=2; i*i<=N; i++){
        if(sieve[i] == true){
            for(int j=i*i; j<=N; j+=i){
                sieve[j] = false;
            }
        }
    }

}
vector<int> generatePrimes(int N){
    vector<int> p;
    for(int i=2; i<=N; i++){
        if(sieve[i] == true){
            p.push_back(i);
        }
    }
    return p;
}
int main(){
    // o(10^6)
    createSieve();
    int t;
    cin>>t;
    while(t--){
        int l, r;
        cin>>l>>r;
        // 
        // step 1 : generate all primes till sqrt(r)
      vector<int> primes = generatePrimes(sqrt(r));
      // step 2: create a dummy array of size (r-l+1)
      int dummy[r-l+1];
      for(int i=0; i<r-l+1; i++){
        dummy[i] = true;
      }       
      // step : mark all multiples of prime numbers as false
      for(auto pr: primes){
        int firstMultiple = (l/(int)pr)*pr;
        if(firstMultiple < l) firstMultiple += pr;
        for(int j = max(firstMultiple, pr*pr); j<=r; j+=pr){
            dummy[j-l] = false;

        }

      }
      for(int i=l; i<=r; i++){
        if(dummy[i-l] == 1){
            cout<< i<< " ";
        }
    
      }
      cout<<endl;
    }

}