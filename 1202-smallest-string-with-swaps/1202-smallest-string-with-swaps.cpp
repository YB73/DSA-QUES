class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int up(int node){
        return node == parent[node] ? node : parent[node] = up(parent[node]);
    }
    void ubs(int u, int v){
        int upu = up(u), upv = up(v);
        if(upu == upv) return;
        if(size[upu] < size[upv]){
            parent[upu] = upv;
            size[upv] += size[upu];
        } else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DisjointSet ds(n);
        for(auto pair : pairs){
            int u = pair[0];
            int v = pair[1];
            if(ds.up(u) != ds.up(v)){
                ds.ubs(u, v);
            }
        }
        vector<vector<int>> par(n);
        for(int i=0;i<n;i++){
            int upi = ds.up(i);
            par[upi].push_back(i);
        }
        for(auto upi : par){
            string res;
            int j = 0;
            for(auto child : upi){
                res += s[child];
            }
            sort(res.begin(), res.end());
            for(auto child : upi){
                s[child] = res[j++];
            }
        }
        return s;
    }
};