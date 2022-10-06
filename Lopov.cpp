#include<bits/stdc++.h>
#include<iostream>
#define ll long long 
using namespace std;

bool cmp(pair<int ,int>&a, pair<int ,int>&b){
    if(a.second>b.second){
        return true;
    }
    else if(a.second == b.second){
        if(a.first<b.first){
            return true;
        }
    }
    return false;

}









int main(){
int n, k;
cin>>n>>k;
vector<pair<int, int>> items(n); 
// first -> mass and second -> value
for(int i=0; i<n; i++){
    cin>>items[i].first>>items[i].second;

}
vector<int> bags(k);
for(int i=0; i<k; i++){
    cin>>bags[i];
}
multiset<int> ms;
for(int i=0; i<k; i++){
    ms.insert(bags[i]);
}
sort(items.begin(), items.end(), cmp);
ll total = 0;
for(int i=0; i<n; i++){
    if(ms.empty()){
        break;
    }
    auto itr = ms.lower_bound(items[i].first);
    if(itr == ms.end()){
        continue;
    }
    total += items[i].second;
}
cout<<total<<endl;
}