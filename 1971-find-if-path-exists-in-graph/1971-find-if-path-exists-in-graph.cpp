class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 0;
        }
    }
    int up(int node){
        return (node == parent[node]) ? node : parent[node] = up(parent[node]);
    }  
    void ubs(int u, int v){
        int upu = up(u);
        int upv = up(v);
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        bool flag = false;
        DisjointSet ds(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(ds.up(u) != ds.up(v)){
                ds.ubs(u,v);
            }
        }
        if(ds.up(source) == ds.up(destination)) flag = true;
        return flag;
    }
};