// find the number of arithmetic triplets in the array, where the difference between successive elements is diff ( a given difference )
#include<bits\stdc++.h>
using namespace std;
int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[j] - nums[i] == diff && nums[k] - nums[j] == diff){
                        count++;
                    }
                }
            }
        }
        return count;
    }



int main(){
    int n;
    cout<<"Enter size: "<<endl;
    cin>>n;
    vector<int> nums;
    cout<<"Enter elements:"<<endl;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        nums.push_back(x);

    }
    int diff;
    cout<<"Enter difference "<<endl;
    cin>>diff;
    int c = arithmeticTriplets(nums, diff);
    cout<<"The number of triplets are : "<<c<<endl;
}