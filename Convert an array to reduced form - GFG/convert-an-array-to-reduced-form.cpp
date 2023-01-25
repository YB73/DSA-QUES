//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	    int temp[n];
    memcpy(temp, arr, n*sizeof(int));
 
    // Sort temp array
    sort(temp, temp + n);
 
    
    unordered_map<int, int> umap;
 
    
    int val = 0;
    for (int i = 0; i < n; i++)
        umap[temp[i]] = val++;
 
    // Convert array by taking positions from
    // umap
    for (int i = 0; i < n; i++)
        arr[i] = umap[arr[i]];
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends