class Union
{
public:
   vector<int> parent , rank ; 
   Union(int n )
   {
      rank.resize(n+1,0);
      parent.resize(n+1,0);
      for(int i = 0 ; i<=n;i++)
      parent[i] = i; 
      
   }
   
   int find(int node )
   {
       if(parent[node] == node)
       return node ; 
       else return parent[node] = find(parent[node]);
   }
   
   void merge(int a, int b)
   {
       int up_a = find(a);
       int up_b = find(b);
       if(up_a==up_b)
       return ; 
       if(rank[up_a]>rank[up_b])
       {
          parent[up_b] = up_a; 
       }
       else if(rank[up_a]<rank[up_b])
       {
          parent[up_a] = up_b; 
       }
       else 
       {
           parent[up_a] = up_b;
           rank[up_b]++;
           
       }
   }
    
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {  int x = - 1 , y = -1 ;
       Union ds(edges.size());
       for(int i = 0;i<edges.size();i++ )
       {
           if(ds.find(edges[i][0])==ds.find(edges[i][1]))
           {
               x = edges[i][0];
               y = edges[i][1];
           }
           else ds.merge(edges[i][0],edges[i][1]);
       } 
       return {x,y};
    }
};