#include<bits\stdc++.h>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
void build(string b, int i, const string & digits, const vector < string > & chars, vector<string> & c){
    if(digits.size() == i){
        c.push_back(b);
        return;
    }
    int d = digits[i] - '0';
    for(char ch : chars[d]){
        build(b + ch, i+1, digits, chars, c);
    }
}
vector<string> letterCombinations(string digits){
if(!digits.size()){
    return {};
}
vector <string> c;
const vector<string> ch = {
    "0",
    "1",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};
string b;
build(b, 0, digits, ch, c);
return c;

}








int main(){
    string digits;
    cout<<"Input the phone number digits "<<endl;
    cin>>digits;
    
    vector<string> c;
    c = letterCombinations(digits);
    int l = c.size();
    for(int i=0; i<l; i++){
        cout<<c[i]<<" ";
    }
}