class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
      int n = items.size();
 	int m = queries.size();

 	sort(begin(items), end(items));

 	vector<pair<int, int>> newQueries;
 	int i=0; 
 	for(auto& q : queries) {
 		newQueries.push_back({q, i++});
 	}

 	sort(begin(newQueries), end(newQueries));

 	int idx = 0, maxBeauty = 0;
 	vector<int> answer(m, 0);

 	for(auto& [query, index] : newQueries) {

 		while(idx < n && items[idx][0] <= query) {
 			maxBeauty = max(maxBeauty, items[idx][1]);
 			idx++;
 		}

 		answer[index] = maxBeauty;
 	}

 	return answer;
    }
};