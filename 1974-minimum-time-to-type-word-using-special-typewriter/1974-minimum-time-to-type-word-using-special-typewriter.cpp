class Solution {
public:
    int minTimeToType(string word) {
      char st = 'a';   // starting character from where we'll measure time for first character of the word given
        int ans = 0; 
        for(auto i : word){
            ans += 1 + min(abs(i-st), abs(26-abs(i-st)));
            st = i;
        }
        return ans;
    }
};