class Solution {
public:
    string convert(string s, int numRows) {
        int row = numRows;
        if(row == 1) return s;
	string result;
	int key1 = 2*(row-1), key2 = 0;
	for(int i = 0; i < row; i++){
		int j = i;
		if(i == 0){
			while(j < s.length()){
				result.push_back(s[j]);
				j += key1;
			}
		}
		else if(i == row-1){
			while(j < s.length()){
				result.push_back(s[j]);
				j += key2;
			}
		}
		else {
			bool flag = true;
			while(j < s.length()){
				result.push_back(s[j]);
				if(flag) {
					j += key1;
					flag = false;
				}
				else {
					j += key2;
					flag = true;
				}
			}
		}
		key1-=2;
		key2+=2;
	}
	return result;
        
    }
};