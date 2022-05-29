#include<bits/stdc++.h>
using namespace std;
int N;
bool sorted(int *arr, int i){
    
    if(i == N-1){
        return true;
    }
    return ((arr[i] < arr[i+1]) && sorted(arr,i+1));
}


int main(){
    cout<<"Enter number of elements in array : "<<endl;
    cin>>N;
    int arr[N];
    cout<<"Enter array elements : "<<endl;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    if( sorted(arr,0)){
        cout<<"The array is sorted."<<endl;

    }
    else{
        cout<<"The array is not sorted : "<<endl;
    }

    return 0;
}