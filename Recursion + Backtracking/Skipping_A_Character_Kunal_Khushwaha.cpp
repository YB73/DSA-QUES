#include<bits\stdc++.h>
using namespace std;

void skip(string p, string up){
 if(up.length() == 0){
    cout<<p<<endl;
 }
 char ch = up[0];
 if( ch == 'a'){
    skip(p, up.substr(1));
 }
 else{
    skip(p+ch, up.substr(1));
 }
}
int main(){
    string p, up;
    cout<<"Enter up: "<<endl;
    cin>>up;
    skip(p, up);
    

}