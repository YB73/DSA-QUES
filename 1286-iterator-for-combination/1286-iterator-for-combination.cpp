class CombinationIterator {
private:
    string s;
    int n;
    vector<string> ans;
    int x=0;
    void solve(string s,int n,string a,int idx)
    {
        if(a.size()==n) ans.push_back(a);
        for(int i=idx;i<s.size();i++)
        {
            a+=s[i];
            solve(s,n,a,i+1);
            a.pop_back();
        }

    }
public:
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        n = combinationLength;
        solve(s,n,"",0);
        // for(int i=0;i<ans.size();i++)
        // {
        //     cout<<ans[i]<<endl;
        // }
    }
    
    string next() {
        return ans[x++];
    }
    
    bool hasNext() {
        if(x<ans.size()) return true;
        return false;
    }
};


/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */