#include<bits\stdc++.h>
using namespace std;




int main(){
    int n;
    cout<<"Enter the number of elements to be entered in the array:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];

    }
    int max = arr[0];
    int secondMax;
    for(int i=1 ; i<n ; i++){
        if(arr[i] > max){
            secondMax = max;
            max = arr[i];
            
        }
        else if(arr[i] > secondMax && arr[i] < max){
            secondMax = arr[i];
        }

    }
    cout<<"The second largest element is:"<<secondMax<<endl;
}