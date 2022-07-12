#include<bits\stdc++.h>
using namespace std;

int mySqrt(int n){
    int l = 1;
    int r = n/2;
    int ans;
    long temp;
    if(n<=1){
        return n;
    }

    while(l<=r){
        int mid = (l+r)/2;
        temp = (long)mid * (long)mid;
        if(temp == n){
            return mid;
        }
        else if(temp < n){
            ans = mid, l = mid+1;
        }
        else{
            r = mid-1;
        }

    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number for sqrt"<<endl;
    cin>>n;
    int x = mySqrt(n);
    cout<<"The sqrt is "<<x<<endl;
}