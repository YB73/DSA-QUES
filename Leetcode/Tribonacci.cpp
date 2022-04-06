#include<bits/stdc++.h>
#include<math.h>
#include<vector>
using namespace std;
int trib(int n) {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    //    if(n == 0){
    //        return 0;
    //    } 
    //     if(n == 1){
    //         return 1;
    //     }
    //     if(n == 2){
    //         return 1;
    //     }
    //     return (trib(n-1) + trib(n-2) + trib(n-3));
    for(int i=3;i<=n;i++){
        nums.push_back(nums[i-1] + nums[i-2] + nums[i-3]); 
    }
    return nums[n];
    }
    int main(){
        int n;
        cout<<"Enter the number for which you want to find the tribonaccci value : "<<endl;
        cin>>n;
        int res = trib(n);
        cout<<res<<endl;

        
    }