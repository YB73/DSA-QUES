class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
         long long totalbeans=0;
  for(int i=0;i<beans.size();i++)
  {
      totalbeans=totalbeans+beans[i];
  }
         long long remove=totalbeans;  //you can max remove all elements 
  
  for(int j=0;j<beans.size();j++)
  {
      long long beansleft=beans[j]*(beans.size()-j); 
      remove= min(remove,(totalbeans-beansleft));
     
  }
  
  return remove;
        
        
    }
};