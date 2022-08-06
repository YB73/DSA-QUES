// Given an array arr[] of size n, its prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] … arr[i].



#include<bits\stdc++.h>
using namespace std;
 

 void fillPrefixSum(int arr[], int n){
    int prefixSum[n];
    prefixSum[0] = arr[0];
    for(int i = 1; i<n; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
    for(int i=0; i<n; i++){
        cout<<prefixSum[i]<<" ";
    }
 }









int main(){
    int n;
    cout<<"Enter the size : "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
   fillPrefixSum(arr, n);
   return 0;
}