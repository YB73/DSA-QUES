class Solution {
public:
    

    void fun(vector<pair<int,int>>& v,vector<int>& visited,int i,vector<vector<int>>& adj,int parent,unordered_map<int,int>& mp,vector<int>& favorite){
     
     int j;
     mp[i]=1;
     visited[i]=1;
     int sum;
     int c=1;
     for(j=0;j<adj[i].size();j++){
      
       if(visited[adj[i][j]]==0){  
         fun(v,visited,adj[i][j],adj,i,mp,favorite); 
       
      }
      else if(visited[adj[i][j]]==1){
          
          if(adj[i][j]==parent){
                v.push_back(make_pair(parent,i));    
          }     
      }
      if(adj[i][j]!=parent && favorite[i]!=adj[i][j]){
         
             sum=1+mp[adj[i][j]];
      if(sum>=c){
          c=sum;
      } 
      }   

     }
     mp[i]=c;
     return;
          
    }
     void check(vector<int> ad[],int node,vector<int>&vis,int a,int& maxi)
    {
        
        a++;
        vis[node]=a;
        for(auto x:ad[node])
        {
            if(vis[x]>0)
            {
                maxi = max(maxi,vis[node]-vis[x]+1);
            }
            else if(vis[x]==0)
            {
                check(ad,x,vis,a,maxi);
            }
        }
        vis[node]=-1;
        return;
    }
    
  
   
    int maximumInvitations(vector<int>& favorite) {
        
        int i,j;
        int ans=0;
        int n=favorite.size();
        if(n<=2){
            return n;
        }
        vector<vector<int>> adj(n);
        for(i=0;i<n;i++){
            adj[favorite[i]].push_back(i);
        }
        vector<int>vis(n+1,0);
        vector<int>ad[n+1];
        for(int i=0;i<n;i++)
        {
            if(favorite[i]!=-1)
            {
                ad[i].push_back(favorite[i]);
            }
        }
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                int a = 0;
                check(ad,i,vis,a,maxi);
            }
        }
        ans=max(ans,maxi);

    vector<int> visited(n);
    for(i=0;i<n;i++){
        visited[i]=0;
    }
   unordered_map<int,int> mp;
   vector<pair<int,int>> v;
   vector<int> v1;
   
   
   
   for(i=0;i<n;i++){
       visited[i]=0;
   }
   
  for(i=0;i<n;i++){
      if(visited[i]==0){
         
          fun(v,visited,i,adj,-1,mp,favorite);
      }
  }
  int score=0;
 
  for(i=0;i<v.size();i++){
   
      score=score+mp[v[i].first]+mp[v[i].second];
  }
ans=max(ans,score);
    
   return ans;

    }
};