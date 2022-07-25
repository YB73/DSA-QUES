#include<bits\stdc++.h>
using namespace std;
string addBinaryStrings(string A, string B){
    string res;
    int carry = 0;
    if(A.size() > B.size()){
        addBinaryStrings(B, A);

    }
    int diff = B.size() - A.size();

    string padding;
    int sum = 0;
    int i = A.size() - 1;
    int j = B.size() - 1;
    while(i>=0 || j>=0 || sum == 1){
        sum = carry + (i>=0 ? A[i] - '0' : 0) + (j>=0 ? B[j] - '0' : 0);
        if(sum > 1){
            carry = 1;
            sum = 0;
        }
        else{
            carry = 0;
        }
        res = char(sum + '0') + res;
        i--;
        j--;
    }
    if(carry == 1){
        res = char(carry + '0') + res;
    }
    return res;

}


int main(){
    string a, b;
    cout<<"Enter the first string:"<<endl;
    cin>>a;
    cout<<"Enter the second string:"<<endl;
    cin>>b;
    string c;
    c = addBinaryStrings(a, b);
    cout<<"The sum of the two binary strings is: "<<endl;
    cout<<c<<endl;

}