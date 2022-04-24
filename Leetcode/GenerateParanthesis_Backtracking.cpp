// class Solution {
// public:
//       vector<string> v;
//     void generateall(int o, int c, int n, string p){
      
//         if(o == n && c == n){
//             v.push_back(p);
//             return;
//         }
//         if( o < n){
//             o+=1;
//             p+="(";
//             generateall(o,c,n,p);
//             o-=1;
//             p.pop_back();
//         }
//        if( c < o){
//             c+=1;
//             p+=")";
//             generateall(o,c,n,p);
//             c-=1;
//             p.pop_back();
//         }
        
//     }
//     vector<string> generateParenthesis(int n) {
//       generateall(1,0,n,"(");
//         return v;
//     }
// };