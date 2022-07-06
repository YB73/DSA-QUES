#include<bits/stdc++.h>
using namespace std;
int N;
bool findt(int *arr, int t, int i){
    if(i == N){
     return false;
    }
    

    return (arr[i] == t || findt(arr,t,i+1));
}

int findind(int *arr, int t, int i){
    if(i == N){
     return -1;
    }
    if(arr[i] == t){
        return i;
    }
    return findind(arr,t,i+1);
}

int main(){
    cout<<"Enter number of elements in array : "<<endl;
    cin>>N;
    int arr[N];
    cout<<"Enter array elements : "<<endl;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int t;
    cout<<"enter the target element : "<<endl;
    cin>>t;


    if( findt(arr,t,0)){
        cout<<"element found at index  "<<findind(arr,t,0)<<endl;

    }
    else{
        cout<<"element not found "<<endl;
    }

    return 0;

    
}