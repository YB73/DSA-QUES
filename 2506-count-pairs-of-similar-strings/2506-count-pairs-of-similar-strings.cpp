class Solution {
public:
    int similarPairs(vector<string>& words) {
      int count=0;
        vector<string> vs;
        for(int i=0; i<words.size(); i++){
            set<char> s;
            for(char m: words[i]) s.insert(m);
            string t="";
            for(auto n: s) t+=n;
            vs.push_back(t);
        }
        for(int i = 0; i < vs.size(); ++i){
            for(int j = i+1; j < vs.size(); ++j){
                if(vs[i] == vs[j]) count++;
            }
        }
        return count;
    }
};