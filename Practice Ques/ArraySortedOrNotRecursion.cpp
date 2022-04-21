#include<bits/stdc++.h>
using namespace std;
int isSortedorNot(int A[], int n){
     if(n==1){
         return 1;
     }
     return (A[n-1] < A[n-2])?0:isSortedorNot(A,n-1);
} 
int main(){
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the array elements : "<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];

    }
    if(isSortedorNot(arr,n) == 0){
        cout<<"The array is not sorted  "<<endl;

    }
   else if(isSortedorNot(arr,n) == 1){
       cout<<"The array is sorted  "<<endl;
   }
   else{
       cout<<isSortedorNot(arr,n);
   }
}