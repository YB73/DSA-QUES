class TrieNode{
  public :
    char data ;
    TrieNode* children[26]; 
   bool isTerminal;
    TrieNode(char ch )
    {
    data =ch ; 
        for(int i =0 ;i<26 ;i++ )
    {
        children[i] = NULL; 
    }
    isTerminal = false; 
  }
    };


class Solution {
public:
TrieNode* root  = new TrieNode('0'); 
    map<string  ,int > m ;
    map<TrieNode* , string >mm; 
    vector<string> ans ;
      void insertUtil(TrieNode* root , string word )
	{
          TrieNode* curr = root ;
          for(auto it: word)
          {
              TrieNode* pt = curr->children[it-'a'];
              if(pt==NULL)
              {
                  TrieNode* child = new TrieNode(it) ;
                  curr->children[it-'a'] = child ;
                 curr =child ; 
              }
              else
                  curr = pt ;
          }
          curr->isTerminal =true ;
          mm[curr] = word ;
	}
    
    
    
    void cal(vector<vector<char>>& b , int i ,int j , TrieNode* ptr , vector<vector<int>>& vis  )
    {
        //base case 
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || vis[i][j] || ptr==NULL)
       return  ;
        
          int ind = b[i][j]-'a'; 
        TrieNode* child = ptr->children[ind]; 
        if(child==NULL)
            return ; 
        
        if(child->isTerminal)
        {
         if(m[mm[child]]==0)
          {
             ans.push_back(mm[child]) ;
          m[mm[child]]++ ;
         }
            child->isTerminal = false ;
        }
        
        vis[i][j] =1; 
        cal(b, i-1, j, child ,vis  ); 
                cal(b, i, j-1, child ,vis   ); 
        cal(b, i+1, j, child ,vis   ); 
        cal(b, i, j+1, child ,vis  ); 

        vis[i][j] =0 ;
        
    }
    
    
    
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        
        
        for(auto it : words)
        {
          insertUtil(root , it ) ;
        }
        
        int n= b.size() ;
        int m = b[0].size() ;
        
        for(int i =0 ; i<n ;i++ )
        {
            for(int j =0 ;j<m ;j++ )
            {
                vector<vector<int>>vis(n , vector<int>(m, 0 )) ;
              
                cal(b ,i , j , root ,  vis ) ;
            }
        }
        return ans ;
    }
};