#include<bits\stdc++.h>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<array>
#include<stack>
#include<queue>
#include<vector>
#include<set>
using namespace std;
#define ll long long 

bool sortByVal(const pair<int, int> &a, const pair<int, int> &b) {
    

    if(a.second == b.second) {
        return a.first < b.first;
    }

    return a.second > b.second;

}
vector<int> sortByFreq(int a[], int n){
    unordered_map <int, int> m;
    vector<int> res;
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    copy(m.begin(), m.end(), back_inserter(v));
    sort(v.begin(), v.end(), sortByVal);

    for(int i=0;i<v.size();i++){
        while(v[i].second--){
            res.push_back(v[i].first);
        }
    }

    return res;
}

int main(){
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n ; i++){
        cin>>arr[i];

    }
    vector<int> res;
    res = sortByFreq(arr,n);

    for(int i = 0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;

}