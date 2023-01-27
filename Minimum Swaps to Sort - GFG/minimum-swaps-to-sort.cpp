//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	        vector<int> arr = nums;
	    	int n = arr.size();
        vector<pair<int, int>> graph(n);
        // along with its index in the original vector
        for (int i = 0; i < n; i++) {
          // values in the vector
          graph[i].first = arr[i];
          // index of the particular value.
          graph[i].second = i;
        }

        // sort the vector according to the values
        sort(graph.begin(), graph.end());

        // variable to store the answer
        int minimum_swaps = 0;
        int i = 0;
        while (i < n) {
          // If there is no need to swap then continue
          if (graph[i].second == i || graph[i].first == arr[i]) {
            ++i;
            continue;
          } else {
            // cycle size
            int cycle_size = 0;
            // stay on the same position until, we fulfill the criterion
            while ((graph[i].second != i && graph[i].first != arr[i])) {

              // swap the values accordingly

              swap(graph[i].first, graph[graph[i].second].first);
              // swap the indices also within the graph vector also
              swap(graph[i].second, graph[graph[i].second].second);
              // increment cycle size
              cycle_size++;
            }
            // add the cycle size to swaps.
            if (cycle_size > 0)
              minimum_swaps += (cycle_size);
            // move to the next index
            ++i;
          }
        }
        return minimum_swaps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends