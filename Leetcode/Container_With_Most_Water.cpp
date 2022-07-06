#include<bits/stdc++.h>
#include<cmath>
#include<conio.h>
#include<algorithm>
#include<array>
using namespace std;
int maxArea(int height[], int size){
    int maxA = INT_MIN;
    int l = 0;
    int r = size - 1;
    while(l < r){
        int shorterLine = min(height[l], height[r]);
        maxA = max(maxA, shorterLine * (r - l));
        if( height[l] < height[r]){
            l++;
        }
        else{
            r--;
        }
    }
    return maxA;
}


int main(){
    int n;
    cout<<"Input the number of containers : "<<endl;
    cin>>n;
    int height[n];
    for(int i=0;i<n;i++){
        cin>>height[i];

    }
    int a;

   a =  maxArea(height, n);
   cout<<a;
}