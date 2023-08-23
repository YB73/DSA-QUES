class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp; 
        for(auto a:s){
            mp[a]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto a:mp){
            pq.push({a.second,a.first});
        }

        string str="";
        while(pq.size()>1){
            auto t1=pq.top();
            pq.pop();
            auto t2=pq.top();
            pq.pop();

            str+=t1.second;
            str+=t2.second;
            t1.first--;
            t2.first--;

            if(t1.first>0)  pq.push(t1);
            if(t2.first>0)  pq.push(t2);
        }

        if(!pq.empty()){
            if(pq.top().first > 1)  return "";
            else    str+=pq.top().second;
        }

        return str;
    }
};