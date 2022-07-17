#include<bits\stdc++.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<ctime>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>

using namespace std;

int row,col;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};



bool backtrack(int i, int j, vector<vector<char>> &board, string word, unsigned int x){
    if(x>=word.size()){
        return true;
    }
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[x]){
        return false;
    }
    char t = board[i][j];
    board[i][j] = '#';
    
    
    for(int a=0 ; a<4; a++){
        if(backtrack(i + dx[a], j+ dy[a], board, word, x+1)){
            return true;
        }
    }
    board[i][j] = t;
    return false;
}




bool exist(vector<vector<char>>& board, string word){
    row = board.size();
    col = board[0].size();
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(backtrack(i,j,board,word,0)){
                return true;
            }
        }
    }
    return false;
} 

int main(){
    string str;
    cout<<"Enter the word to be searched:"<<endl;
    cin>>str;
    int n = str.length();
    vector<vector<char>> board;
    char c;
    int m, y;
    cout<<"Enter the number of rows:"<<endl;
    cin>>m;
    cout<<"Enter the number of columns:"<<endl;
    cin>>y;
    vector<char> r;
    for(int i=0 ; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>c;
            r.push_back(c);
        }
    }
    board.push_back(r);
    // backtrack(board, s);
    // cout<<sqrt(board[0].size())<<endl;
    if(exist(board, str)){
        cout<<"Word Found"<<endl;
    }
    else{
        cout<<"No Luck"<<endl;
    }

}