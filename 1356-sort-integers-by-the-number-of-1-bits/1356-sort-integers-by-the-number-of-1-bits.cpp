class Solution {
public:
    int getoneBits(int a){
        int count = 0;
    while (a) {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        vector<pair<int, int>> bits;
        for(int i=0; i<arr.size(); i++){
            bits.push_back(make_pair(arr[i], getoneBits(arr[i])));
        }
        sort(bits.begin(),bits.end(),
            [&](pair<int,int> a, pair<int,int> b)->auto
             {
                 return a.second==b.second?(a.first<b.first):(a.second<b.second);
             }
            );
        
        for(int i=0; i<bits.size(); i++){
            res.push_back(bits[i].first);
        }
        return res;
    }
};