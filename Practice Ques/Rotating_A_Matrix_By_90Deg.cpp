#include<bits\stdc++.h>
#include<array>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<functional>
#include<iostream>
using namespace std;
int n;
void rotate90(int arr[][n], int n){
    for(int i=0;i<n;i++){
        reverse(arr[i], arr[i]+n);

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main(){
    cout<<"Enter the  number of rows and columns of the sq matrix"<<endl;
    cin>>n;
    int mat[n][n];
    cout<<"Enter the elements of the matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    rotate90(mat,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
            
        }
        cout<<endl;
    }
}