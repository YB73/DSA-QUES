#include<bits/stdc++.h>
#include<map>
#include<utility>
#include<cmath>
#include<vector>

using namespace std;
int findGreatest(vector<int> &arr, int n) {
    int gn = -1;
    map<int , int> m;
    int max = 0;
    for(int i=0; i<n; i++){
        m[arr[i]]++;
    }
    sort(arr.begin() , arr.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int mul = arr[i]*arr[j];
            if(m.find(mul) != m.end()){
                if(mul > max){
                    max = mul;
                    gn = max;
                }
            }
        }
    }
    return gn;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);

    }
    int g = findGreatest(arr, n);
    cout<<"The greatest number which is a product is: "<<g<<endl;
}