class Solution {
public:
    void build(string builder, int i,
    const string & digits,
      const vector < string > & chars, vector < string > & c) {
    if (i == digits.size()) {
      c.push_back(builder);
      return;
    }
        int d = digits[i] - '0';
    for (char ch: chars[d]) {
      build(builder + ch, i + 1, digits, chars, c);
    }
  }
    vector<string> letterCombinations(string digits) {
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
};