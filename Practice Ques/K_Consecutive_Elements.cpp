// max sum of k consecutive elements
#include<bits\stdc++.h>
using namespace std;


int maxsum(int a[], int n, int k){
    int max_sum = 0;
    int sum = 0;
    for(int i=0; i<k; i++){
        sum += a[i];
    }
    max_sum = sum;
    for(int i=k; i<n; i++){
        sum += a[i] - a[i-k];
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}


int main(){
    int n;
    int k;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;
    int a[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int y = maxsum(a, n, k);
    cout<<"The max sum of k consecutive elements is : "<<y<<endl;
}