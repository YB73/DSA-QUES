class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
          vector<string> res;
    unordered_map<string, int> m;
    int pos = 0;
    for(auto st: cpdomains){
        int cnt = 0;
        pos = st.find(' ');
        cnt = stoi(st.substr(0, pos));
        string domain = st.substr(pos + 1);
        int len = domain.length();
        for(int i=0; i<len; i++){
            if(domain[i] == '.'){
                string sub = domain.substr(i+1);
                m[sub] += cnt;

            }

        }
        m[domain] += cnt;
    }
    for(auto it: m){
        res.push_back(to_string(it.second) + " " + it.first);
    }
    return res;
    
    }
};