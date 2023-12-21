class Solution {
public:
   bool checkCycle(int node,vector<int>&vis,vector<int>&dfsVis,
   vector<unordered_set<int>>&adj)
   {
       vis[node]=1;
       dfsVis[node]=1;
       for (auto it : adj[node] )
       {
           if (!vis[it])
           {
               if (checkCycle(it,vis,dfsVis,adj)) return true;
           }
           else{
               if (dfsVis[it])
               {
                   return true;
               }
           }
       }
       dfsVis[node]=0;
       return false;
   }
    bool isPrintable(vector<vector<int>>& targetGrid) 
    {
        int n=targetGrid.size();
        int m=targetGrid[0].size();
      vector<unordered_set<int>>adj(61);
      for (int i=1;i<=60;i++)
      {
          int minx=n;
          int miny=m;
          int maxx=0;
          int maxy=0;
          for (int x=0;x<n;x++)
          {
              for (int y=0;y<m;y++)
              {
                  if (targetGrid[x][y]==i)
                  {
                     minx=min(x,minx);
                     miny=min(y,miny);
                     maxx=max(x,maxx);
                     maxy=max(y,maxy);
                  }
              }
          }
          for (int x=minx;x<=maxx;x++)
          {
              for (int y=miny;y<=maxy;y++)
              {
                  if (targetGrid[x][y]!=i)
                  {
                      adj[i].insert(targetGrid[x][y]);
                  }
              }
          }
      }  
      vector<int>vis(61,0);
      vector<int>dfsVis(61,0);
      for (int i=1;i<=60;i++)
      {
          if (vis[i]==0)
          {
              if (checkCycle(i,vis,dfsVis,adj)) return false;
          }
      } 
      return true;
    }
};