#include<bits\stdc++.h>
using namespace std;

bool isGoodArray(vector<int>& nums) {
    int gcd = nums[0];
    for(int i=1; i<nums.size(); i++) {
        gcd = __gcd(gcd, nums[i]);

    }
    if(gcd == 1){
        return true;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: "<<endl;
    cin>>n;
    vector<int> nums;
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    bool res = isGoodArray(nums);
    cout<<res<<endl;
}