#include<bits\stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int, int> hash;
    
    for(int i=0; i<nums.size(); i++) {
        if(hash.find(target-nums[i]) != hash.end()) {      // checking if the complement is in the hashmap 
            result.push_back(hash[target-nums[i]]);   // if yes, then we push it to the result vector
            result.push_back(i);
            return result;   // returning result vector

        }
        hash[nums[i]] = i;   // inserting elements and index as key-value pair in hash table 

    }
    return result;
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
    int target;
    cout<<"Enter the target sum: "<<endl;
    cin>>target;
    vector<int> res;
    res = twoSum(nums, target);
    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}